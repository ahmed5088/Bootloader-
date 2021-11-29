/**
 * \file IfxStdIf.h
 * \brief Standard interface types
 * \ingroup IfxLld
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:23 GMT$
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * \defgroup library_srvsw_stdif Standard interface
 * \ingroup library_srvsw
 *
 *
 *
 * \par Terms
 *
 * Term                      |  Description
 * ------------------------- | -------
 * Standard Interface        | Interface defined in this document
 * Interface Driver          | Specific device driver as defined by the iLLD
 * Standard Interface Driver | Specific interface driver which implements the Standard Interface
 * API used at runtime       | API that are used after initialization
 * Module                    | Hardware functional block / IP
 *
 * \par Overview
 * The Standard Interface provides generic runtime API written in C for common use case application. It abstracts the underlaying Interface Driver,
 * i.e. the runtime API is completely device independent. It provides generic API for common use case application.
 *
 * Example of Standard Interface:
 * - Serial communication interface
 * - PWM interface
 * - Position sensor interface
 * - Timer interface
 * - EEPROM interface
 *
 * The target is to be able to exchange the microcontroller or external connected devices on which the application is based with a minimal impact
 *  on the application code, to reduce the application software development and maintenance effort.  This is archived by the Standard Interface,
 * for which, changing the hardware only requires the update of the device configuration settings and the device initialization code. The API used
 * at runtime, which represents the majority and the complexitity of the related code keep unchanged.
 *
 * Motivation: because the current software developed for the automotive applications mainly don�t use C++, the Standard Interface provides a common
 *  definition for the device driver and an alternative layer for different hardware instead of using C++ interface wrapper class.
 *
 *
 * The below figure shows the layers used and an example of APIs used by the application.
 * \image html "StandardInterfaceLayers.png" "Standard interface layers"
 * \image html "StandardInterfaceDataPipeExample.png" "Standard interface example: Serial interface as data pipe"
 * \image html "StandardInterfaceTimerExample.png" "Standard interface example: Timer"
 *
 * The Standard Interface is implemented by Standard Interface wrapper by providing the function pointer to the custom functions. This gives
 * the possibility to the programmer to use it or not. When used, it increases the code portability but slightly decreases the performance in
 * term of run time execution and code size. When not used, the performance is not affected.
 *
 *
 * \par Definition
 * The standard interface requires the definition of at least two components: the standard interface component and the standard interface wrapper
 * component. The standard interface component defines for each standard interface a standard interface object and a set of standard APIs used at
 * runtime by the application. The standard interface wrapper component initializes the standard interface component by linking it to the interface
 * driver.
 *
 * \attention:  The application shall explicitly use the API provided by the standard interface component at runtime to access driver�s parameters
 * (setter/ getter) or action (methods). Trying to access members of the standard interface component directly though the object may not guaranty
 * future code compatibility. The same applies to the interface driver (reminder).
 *
 *
 * \par Convention
 *
 * The Standard interface defines the following files:
 * Path/File                                       | Description
 * ----------------------------------------------- | -----------------
 * 1_SrvSw/StdIf/IfxStdIf.h                        | Global standard interface definitions
 * 1_SrvSw/StdIf/IfxStdIf_\<standard interface\>.h   | Specific standard interface definitions
 * TCxxx/\<Module\>/Ifx\<Module\>_\<interface\>.h/c      | Specific standard interface wrapper initialization API are reconized by the name Ifx<Module>_<interface>_StdIf<std interface>Init()
 * TCxxx/\<Module\>/Ifx\<Module\>_\<interface\>.h/c      | Specific standard interface wrapper function API are named according to the interface driver naming rules
 *
 */

#ifndef IFXSTDIF_H_
#define IFXSTDIF_H_ 1

#include "Ifx_Types.h"

typedef void *IfxStdIf_InterfaceDriver; /**< \brief Pointer to the specific interface driver */

#endif /* IFXSTDIF_H_ */
