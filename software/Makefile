all:
	

FHNW_PRO4E_TEAM8:
	mv ./Marlin/Configuration.h ./Marlin/Configuration.h.bak
	mv ./Marlin/Configuration_adv.h ./Marlin/Configuration_adv.h.bak
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration.h ./Marlin/Configuration.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration_adv.h ./Marlin/Configuration_adv.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Bootscreen.h ./Marlin/_Bootscreen.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Statusscreen.h ./Marlin/_Statusscreen.h

clean:
	mv ./Marlin/Configuration.h.bak ./Marlin/Configuration.h
	mv ./Marlin/Configuration_adv.h.bak ./Marlin/Configuration_adv.h
	rm -f ./Marlin/_Bootscreen.h ./Marlin/_Statusscreen.h
