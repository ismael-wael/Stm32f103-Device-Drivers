#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "SPI_config.h"
#include "SPI_interface.h"

 const SPI_t HSPIArrayOfSPI [ NUM_OF_SPI ] = {

		{
				.CPHA = readThenWrite,
				.CPOL = idle_zero,
				.baudrate = fclk_div_2,
				.dataFrameFormat = Data_8bit,
				.frameFormat = MSB_first,
				.mode = SLAVE,
				.rxonloy = Full_Duplex,
				.ssm = SSM_disable
		},

		{
				.CPHA = readThenWrite,
				.CPOL = idle_zero,
				.baudrate = fclk_div_2,
				.dataFrameFormat = Data_8bit,
				.frameFormat = MSB_first,
				.mode = SLAVE,
				.rxonloy = Full_Duplex,
				.ssm = SSM_disable
		}

};
