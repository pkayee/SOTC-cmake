all: kernel loader gamecore manager dbgcore dbgmgr grptools maptool pathtool prttool


loader: SCPS_150.97.ninja FORCE
	@echo Building SCPS_150.97...
	@ninja -f SCPS_150.97.ninja


kernel: KERNEL.XFF.ninja FORCE
	@echo Building KERNEL.XFF...
	@ninja -f KERNEL.XFF.ninja


gamecore: GAMECORE.XFF.ninja FORCE
	@echo Building GAMECORE.XFF...
	@ninja -f GAMECORE.XFF.ninja


manager: MANAGER.XFF.ninja FORCE
	@echo Building MANAGER.XFF...
	@ninja -f MANAGER.XFF.ninja


dbgcore: DBGCORE.XFF.ninja FORCE
	@echo Building DBGCORE.XFF...
	@ninja -f DBGCORE.XFF.ninja


dbgmgr: DBGMGR.XFF.ninja FORCE
	@echo Building DBGMGR.XFF...
	@ninja -f DBGMGR.XFF.ninja


grptools: GRPTOOLS.XFF.ninja FORCE
	@echo Building GRPTOOLS.XFF...
	@ninja -f GRPTOOLS.XFF.ninja


maptool: MAPTOOL.XFF.ninja FORCE
	@echo Building MAPTOOL.XFF...
	@ninja -f MAPTOOL.XFF.ninja


pathtool: PATHTOOL.XFF.ninja FORCE
	@echo Building PATHTOOL.XFF...
	@ninja -f PATHTOOL.XFF.ninja


prttool: PRTTOOL.XFF.ninja FORCE
	@echo Building PRTTOOL.XFF...
	@ninja -f PRTTOOL.XFF.ninja


build/SCPS_150.97/%.o: SCPS_150.97.ninja FORCE
	@ninja -f SCPS_150.97.ninja $@


build/KERNEL.XFF/%.o: KERNEL.XFF.ninja FORCE
	@ninja -f KERNEL.XFF.ninja $@


build/GAMECORE.XFF/%.o: GAMECORE.XFF.ninja FORCE
	@ninja -f GAMECORE.XFF.ninja $@


build/MANAGER.XFF/%.o: MANAGER.XFF.ninja FORCE
	@ninja -f MANAGER.XFF.ninja $@


build/DBGCORE.XFF/%.o: DBGCORE.XFF.ninja FORCE
	@ninja -f DBGCORE.XFF.ninja $@


build/DBGMGR.XFF/%.o: DBGMGR.XFF.ninja FORCE
	@ninja -f DBGMGR.XFF.ninja $@


build/GRPTOOLS.XFF/%.o: GRPTOOLS.XFF.ninja FORCE
	@ninja -f GRPTOOLS.XFF.ninja $@


build/MAPTOOL.XFF/%.o: MAPTOOL.XFF.ninja FORCE
	@ninja -f MAPTOOL.XFF.ninja $@


build/PATHTOOL.XFF/%.o: PATHTOOL.XFF.ninja FORCE
	@ninja -f PATHTOOL.XFF.ninja $@


build/PRTTOOL.XFF/%.o: PRTTOOL.XFF.ninja FORCE
	@ninja -f PRTTOOL.XFF.ninja $@


SCPS_150.97.ninja:
	@./configure.py -c -t loader


KERNEL.XFF.ninja:
	@./configure.py -c -t kernel


GAMECORE.XFF.ninja:
	@./configure.py -c -t gamecore


MANAGER.XFF.ninja:
	@./configure.py -c -t manager


DBGCORE.XFF.ninja:
	@./configure.py -c -t dbgcore


DBGMGR.XFF.ninja:
	@./configure.py -c -t dbgmgr


GRPTOOLS.XFF.ninja:
	@./configure.py -c -t grptools


MAPTOOL.XFF.ninja:
	@./configure.py -c -t maptool


PATHTOOL.XFF.ninja:
	@./configure.py -c -t pathtool


PRTTOOL.XFF.ninja:
	@./configure.py -c -t prttool


FORCE:


clean:
	@rm -rf asm assets build
	@rm -rf *.ninja
.PHONY : clean
