# Generate/check/update a .h file to reflect the values of Makefile
# variables
#
# Example usage (by default, check-conf-h will consider all CFG_*
# and _CFG_* variables):
#
# path/to/conf.h: FORCE
#	$(call check-conf-h)
#
# Or, to include only the variables with the given prefix(es):
#
# path/to/crypto_config.h: FORCE
#	$(call check-conf-h,CFG_CRYPTO_ CRYPTO_)
define check-conf-h
	$(q)set -e;						\
	echo '  CHK     $@';					\
	cnf="$(strip $(foreach var,				\
		$(call cfg-vars-by-prefix,$1),			\
		$(call cfg-make-define,$(var))))";		\
	guard="_`echo $@ | tr -- -/. ___`_";			\
	mkdir -p $(dir $@);					\
	echo "#ifndef $${guard}" >$@.tmp;			\
	echo "#define $${guard}" >>$@.tmp;			\
	echo -n "$${cnf}" | sed 's/_nl_ */\n/g' >>$@.tmp;	\
	echo "#endif" >>$@.tmp;					\
	if [ -r $@ ] && cmp -s $@ $@.tmp; then			\
		rm -f $@.tmp;					\
	else							\
		echo '  UPD     $@';				\
		mv $@.tmp $@;					\
	fi
endef

define cfg-vars-by-prefix
	$(strip $(if $(1),$(call _cfg-vars-by-prefix,$(1)),
			  $(call _cfg-vars-by-prefix,CFG_ _CFG_)))
endef

define _cfg-vars-by-prefix
	$(sort $(foreach prefix,$(1),$(filter $(prefix)%,$(.VARIABLES))))
endef

# Convert a makefile variable to a #define
# <undefined>, n => <undefined>
# y              => 1
# <other value>  => <other value>
define cfg-make-define
	$(strip $(if $(filter y,$($1)),
		     #define $1 1 /* '$($1)' */_nl_,
		     $(if $(filter xn x,x$($1)),
			  /* $1 is not set ('$($1)') */_nl_,
			  #define $1 $($1) /* '$($1)' */_nl_)))
endef

# Returns 'y' if at least one variable is 'y', empty otherwise
# Example:
# FOO_OR_BAR := $(call cfg-one-enabled, FOO BAR)
cfg-one-enabled = $(if $(filter y, $(foreach var,$(1),$($(var)))),y,)

# Returns 'y' if all variables are 'y', empty otherwise
# Example:
# FOO_AND_BAR := $(call cfg-all-enabled, FOO BAR)
cfg-all-enabled =                                                             \
    $(strip                                                                   \
        $(if $(1),                                                            \
            $(if $(filter y,$($(firstword $(1)))),                            \
                $(call cfg-all-enabled,$(filter-out $(firstword $(1)),$(1))), \
             ),                                                               \
            y                                                                 \
         )                                                                    \
     )

# Disable a configuration variable if some dependency is disabled
# Example:
# $(eval $(call cfg-depends-all,FOO,BAR BAZ))
# Will clear FOO if it is initially 'y' and BAR or BAZ are not 'y'
cfg-depends-all =                                                           \
    $(strip                                                                 \
        $(if $(filter y, $($(1))),                                          \
            $(if $(call cfg-all-enabled,$(2)),                              \
                ,                                                           \
                $(warning Warning: Disabling $(1) [requires $(strip $(2))]) \
                    override $(1) :=                                        \
             )                                                              \
         )                                                                  \
     )

# Disable a configuration variable if all dependencies are disabled
# Example:
# $(eval $(call cfg-depends-one,FOO,BAR BAZ))
# Will clear FOO if it is initially 'y' and both BAR and BAZ are not 'y'
cfg-depends-one =                                                                    \
    $(strip                                                                          \
        $(if $(filter y, $($(1))),                                                   \
            $(if $(call cfg-one-enabled,$(2)),                                       \
                ,                                                                    \
                $(warning Warning: Disabling $(1) [requires (one of) $(strip $(2))]) \
                    override $(1) :=                                                 \
             )                                                                       \
         )                                                                           \
     )
