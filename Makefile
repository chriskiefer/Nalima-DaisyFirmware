# Project Name
TARGET = Nalima_Daisy_Firmware

USE_DAISYSP_LGPL=1

APP_TYPE=BOOT_QSPI


# MAXIMILIAN_DIR = Maximilian/src

# Sources
CPP_SOURCES = Nalima_Daisy_Firmware.cpp 
# CPP_SOURCES += ${MAXIMILIAN_DIR}/maximilian.cpp

# C_INCLUDES = -I${MAXIMILIAN_DIR}
# C_INCLUDES += -I../DaisySP-LGPL/Source 
C_INCLUDES += -Ieigen-3.4.0/
C_INCLUDES += -IEigenRand/

# Library Locations
LIBDAISY_DIR = ../DaisyExamples/libDaisy/
DAISYSP_DIR = ../DaisyExamples/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
