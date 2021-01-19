# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  lineareq_config = debug

else ifeq ($(config),release)
  lineareq_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := lineareq

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

lineareq:
ifneq (,$(lineareq_config))
	@echo "==== Building lineareq ($(lineareq_config)) ===="
	@${MAKE} --no-print-directory -C src -f Makefile config=$(lineareq_config)
endif

clean:
	@${MAKE} --no-print-directory -C src -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   lineareq"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"