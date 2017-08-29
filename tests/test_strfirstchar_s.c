/*------------------------------------------------------------------
 * test_strfirstchar_s
 *
 *
 *------------------------------------------------------------------
 */

#include "test_private.h"
#include "safe_str_lib.h"

#define LEN   ( 128 )
#define SHORT_LEN  ( 5 )

int main()
{
    errno_t rc;
    rsize_t  len;

    char *first;
    char  str1[LEN];
    int errs = 0;

/*--------------------------------------------------*/

    rc = strfirstchar_s(NULL, LEN, 'a', &first);
    if (rc != ESNULLP) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
    if (first) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    rc = strfirstchar_s(str1, LEN, 'a', NULL);
    if (rc != ESNULLP) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    rc = strfirstchar_s(str1, 0, 'a', &first);
    if (rc != ESZEROL) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
    if (first) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    rc = strfirstchar_s(str1, RSIZE_MAX_STR+1, 'a', &first);
    if (rc != ESLEMAX) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
    if (first) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    str1[0] = '\0';

    rc = strfirstchar_s(str1, LEN, 'a', &first);
    if (rc != ESNOTFND) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
    if (first) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    strcpy (str1, "Keep it simple");

    rc = strfirstchar_s(str1, LEN, 'z', &first);
    if (rc != ESNOTFND) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
    if (first) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    strcpy (str1, "kEEp it simple");

    rc = strfirstchar_s(str1, LEN, 'E', &first);
    if (rc != EOK) {
        debug_printf("%s %u  Error rc=%d \n",
                     __FUNCTION__, __LINE__, rc);
        errs++;
    }
    if (first != &str1[1]) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    strcpy (str1, "keep it simpleZ");
    len = strlen(str1);

    rc = strfirstchar_s(str1, len, 'Z', &first);
    if (rc != EOK) {
        debug_printf("%s %u  Error rc=%d \n",
                     __FUNCTION__, __LINE__, rc);
        errs++;
    }
    if (first != &str1[14]) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    strcpy (str1, "keep it simpleZZ");

    rc = strfirstchar_s(str1, LEN, 'Z', &first);
    if (rc != EOK) {
        debug_printf("%s %u  Error rc=%d \n",
                     __FUNCTION__, __LINE__, rc);
        errs++;
    }
    if (first != &str1[14]) {
        debug_printf("%s %u  Error  str1=%p  first=%p  rc=%d \n",
                     __FUNCTION__, __LINE__,  str1, first, rc);
        errs++;
    }
/*--------------------------------------------------*/

    return (errs);
}
