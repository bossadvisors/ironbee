ACLOCAL_AMFLAGS = -I ../../acinclude

include $(top_srcdir)/build/common.mk

SUBDIRS = tests
EXTRA_DIST = \
    config-parser.rl                \
    config_private.h                \
    core_private.h                  \
    core_audit_private.h            \
    engine_private.h                \
    module_private.h                \
    rule_engine_private.h           \
    rule_logger_private.h           \
    core_stream_processor_private.h \
    state_notify_private.h


lib_LTLIBRARIES = libironbee.la
libironbee_la_SOURCES =                  \
    action.c                             \
    capture.c                            \
    config.c                             \
    config-parser.c                      \
    config-parser.h                      \
    context_selection.c                  \
    core.c                               \
    core_actions.c                       \
    core_audit.c                         \
    core_context_selection.c             \
    core_operators.c                     \
    core_stream_processor.c              \
    core_tfns.c                          \
    core_vars.c                          \
    engine.c                             \
    engine_manager.c                     \
    engine_manager_control_channel.c     \
    log.c                                \
    logger.c                             \
    logevent.c                           \
    module.c                             \
    operator.c                           \
    parsed_content.c                     \
    rule_engine.c                        \
    rule_logger.c                        \
    server.c                             \
    site.c                               \
    state_notify.c                       \
    stream_pump.c                        \
    stream_processor.c                   \
    transformation.c                     \
    var.c                                \
    $(top_builddir)/lua/ironbee.h

libironbee_la_CPPFLAGS = $(AM_CPPFLAGS)
libironbee_la_CFLAGS = $(AM_CFLAGS)
libironbee_la_LIBADD = $(top_builddir)/util/libibutil.la
libironbee_la_LDFLAGS = $(AM_LDFLAGS)                   \
                        $(LIBM_LDFLAGS)                 \
                        -version-info @LIBRARY_VERSION_INFO@ \
                        -release @LIBRARY_RELEASE@

if DARWIN
install-exec-hook: $(lib_LTLIBRARIES)
	@for l in $(lib_LTLIBRARIES); do \
	  base=`echo $$l | sed 's/\..*//'`; \
	  echo "rebasing $$base..."; \
	  rebase -v $(DESTDIR)$(libdir)/$$base.dylib; \
	done
endif

# Ragel generated files
if HAVE_RAGEL
%.c: %.rl
	(cd $(dir $<); $(RAGEL) -s $(notdir $<))

config-parser.dot: $(srcdir)/config-parser.rl
	$(RAGEL) -V $< > $@

config-parser.svg: config-parser.dot
	dot -Tsvg $<  > $@
endif
