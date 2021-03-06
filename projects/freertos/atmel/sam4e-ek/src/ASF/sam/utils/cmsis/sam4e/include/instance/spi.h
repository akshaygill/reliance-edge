/**
 * \file
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _SAM4E_SPI_INSTANCE_
#define _SAM4E_SPI_INSTANCE_

/* ========== Register definition for SPI peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_SPI_CR                    (0x40088000U) /**< \brief (SPI) Control Register */
  #define REG_SPI_MR                    (0x40088004U) /**< \brief (SPI) Mode Register */
  #define REG_SPI_RDR                   (0x40088008U) /**< \brief (SPI) Receive Data Register */
  #define REG_SPI_TDR                   (0x4008800CU) /**< \brief (SPI) Transmit Data Register */
  #define REG_SPI_SR                    (0x40088010U) /**< \brief (SPI) Status Register */
  #define REG_SPI_IER                   (0x40088014U) /**< \brief (SPI) Interrupt Enable Register */
  #define REG_SPI_IDR                   (0x40088018U) /**< \brief (SPI) Interrupt Disable Register */
  #define REG_SPI_IMR                   (0x4008801CU) /**< \brief (SPI) Interrupt Mask Register */
  #define REG_SPI_CSR                   (0x40088030U) /**< \brief (SPI) Chip Select Register */
  #define REG_SPI_WPMR                  (0x400880E4U) /**< \brief (SPI) Write Protection Mode Register */
  #define REG_SPI_WPSR                  (0x400880E8U) /**< \brief (SPI) Write Protection Status Register */
  #define REG_SPI_RPR                   (0x40088100U) /**< \brief (SPI) Receive Pointer Register */
  #define REG_SPI_RCR                   (0x40088104U) /**< \brief (SPI) Receive Counter Register */
  #define REG_SPI_TPR                   (0x40088108U) /**< \brief (SPI) Transmit Pointer Register */
  #define REG_SPI_TCR                   (0x4008810CU) /**< \brief (SPI) Transmit Counter Register */
  #define REG_SPI_RNPR                  (0x40088110U) /**< \brief (SPI) Receive Next Pointer Register */
  #define REG_SPI_RNCR                  (0x40088114U) /**< \brief (SPI) Receive Next Counter Register */
  #define REG_SPI_TNPR                  (0x40088118U) /**< \brief (SPI) Transmit Next Pointer Register */
  #define REG_SPI_TNCR                  (0x4008811CU) /**< \brief (SPI) Transmit Next Counter Register */
  #define REG_SPI_PTCR                  (0x40088120U) /**< \brief (SPI) Transfer Control Register */
  #define REG_SPI_PTSR                  (0x40088124U) /**< \brief (SPI) Transfer Status Register */
#else
  #define REG_SPI_CR   (*(__O  uint32_t*)0x40088000U) /**< \brief (SPI) Control Register */
  #define REG_SPI_MR   (*(__IO uint32_t*)0x40088004U) /**< \brief (SPI) Mode Register */
  #define REG_SPI_RDR  (*(__I  uint32_t*)0x40088008U) /**< \brief (SPI) Receive Data Register */
  #define REG_SPI_TDR  (*(__O  uint32_t*)0x4008800CU) /**< \brief (SPI) Transmit Data Register */
  #define REG_SPI_SR   (*(__I  uint32_t*)0x40088010U) /**< \brief (SPI) Status Register */
  #define REG_SPI_IER  (*(__O  uint32_t*)0x40088014U) /**< \brief (SPI) Interrupt Enable Register */
  #define REG_SPI_IDR  (*(__O  uint32_t*)0x40088018U) /**< \brief (SPI) Interrupt Disable Register */
  #define REG_SPI_IMR  (*(__I  uint32_t*)0x4008801CU) /**< \brief (SPI) Interrupt Mask Register */
  #define REG_SPI_CSR  (*(__IO uint32_t*)0x40088030U) /**< \brief (SPI) Chip Select Register */
  #define REG_SPI_WPMR (*(__IO uint32_t*)0x400880E4U) /**< \brief (SPI) Write Protection Mode Register */
  #define REG_SPI_WPSR (*(__I  uint32_t*)0x400880E8U) /**< \brief (SPI) Write Protection Status Register */
  #define REG_SPI_RPR  (*(__IO uint32_t*)0x40088100U) /**< \brief (SPI) Receive Pointer Register */
  #define REG_SPI_RCR  (*(__IO uint32_t*)0x40088104U) /**< \brief (SPI) Receive Counter Register */
  #define REG_SPI_TPR  (*(__IO uint32_t*)0x40088108U) /**< \brief (SPI) Transmit Pointer Register */
  #define REG_SPI_TCR  (*(__IO uint32_t*)0x4008810CU) /**< \brief (SPI) Transmit Counter Register */
  #define REG_SPI_RNPR (*(__IO uint32_t*)0x40088110U) /**< \brief (SPI) Receive Next Pointer Register */
  #define REG_SPI_RNCR (*(__IO uint32_t*)0x40088114U) /**< \brief (SPI) Receive Next Counter Register */
  #define REG_SPI_TNPR (*(__IO uint32_t*)0x40088118U) /**< \brief (SPI) Transmit Next Pointer Register */
  #define REG_SPI_TNCR (*(__IO uint32_t*)0x4008811CU) /**< \brief (SPI) Transmit Next Counter Register */
  #define REG_SPI_PTCR (*(__O  uint32_t*)0x40088120U) /**< \brief (SPI) Transfer Control Register */
  #define REG_SPI_PTSR (*(__I  uint32_t*)0x40088124U) /**< \brief (SPI) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM4E_SPI_INSTANCE_ */
