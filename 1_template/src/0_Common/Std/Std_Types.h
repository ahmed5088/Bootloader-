#ifndef STD_TYPES_H
#define STD_TYPES_H

/*==================[inclusions]=============================================*/


#include "Ifx_Types.h" /* Platform specific type declarations */



/*==================[macros]=================================================*/

#if (defined STD_HIGH)
#error STD_HIGH already defined
#endif

#define STD_HIGH 1U

#if (defined STD_LOW)
#error STD_LOW already defined
#endif

#define STD_LOW 0U

#if (defined STD_ACTIVE)
#error STD_ACTIVE already defined
#endif

#define STD_ACTIVE 1U

#if (defined STD_IDLE)
#error STD_IDLE already defined
#endif

#define STD_IDLE 0U

#if (defined STD_ON)
#error STD_ON already defined
#endif

#define STD_ON 1U

#if (defined STD_OFF)
#error STD_OFF already defined
#endif

#define STD_OFF 0U


#ifndef E_OK
#define E_OK 0U
#endif

#ifndef E_NOT_OK
#define E_NOT_OK 1U
#endif


/*==================[end of file]============================================*/
#endif /* ifndef STD_TYPES_H */
