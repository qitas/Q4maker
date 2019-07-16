all:
	

STM32F103ZE:
	mv ./Marlin/Configuration.h ./Marlin/Configuration.h.bak
	mv ./Marlin/Configuration_adv.h ./Marlin/Configuration_adv.h.bak
	cp ./config/examples/FHNW_PRO4E/Configuration.h ./Marlin/Configuration.h
	cp ./config/examples/FHNW_PRO4E/Configuration_adv.h ./Marlin/Configuration_adv.h
	cp ./config/examples/FHNW_PRO4E/_Bootscreen.h ./Marlin/_Bootscreen.h
	cp ./config/examples/FHNW_PRO4E/_Statusscreen.h ./Marlin/_Statusscreen.h
STM32F103RE:
	mv ./Marlin/Configuration.h ./Marlin/Configuration.h.bak
	mv ./Marlin/Configuration_adv.h ./Marlin/Configuration_adv.h.bak
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration.h ./Marlin/Configuration.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration_adv.h ./Marlin/Configuration_adv.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Bootscreen.h ./Marlin/_Bootscreen.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Statusscreen.h ./Marlin/_Statusscreen.h
STM32F407VE:
	mv ./Marlin/Configuration.h ./Marlin/Configuration.h.bak
	mv ./Marlin/Configuration_adv.h ./Marlin/Configuration_adv.h.bak
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration.h ./Marlin/Configuration.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/Configuration_adv.h ./Marlin/Configuration_adv.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Bootscreen.h ./Marlin/_Bootscreen.h
	cp ./config/examples/FHNW_PRO4E_TEAM8/_Statusscreen.h ./Marlin/_Statusscreen.h

clean:
	cp ./config/default/Configuration.h  ./Marlin/Configuration.h
	cp ./config/default/Configuration_adv.h  ./Marlin/Configuration_adv.h
	rm -f ./Marlin/_Bootscreen.h ./Marlin/_Statusscreen.h
