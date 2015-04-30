/*             ----> DO NOT REMOVE THE FOLLOWING NOTICE <----

                   Copyright (c) 2014-2015 Datalight, Inc.
                       All Rights Reserved Worldwide.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; use version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but "AS-IS," WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
/*  Businesses and individuals that for commercial or other reasons cannot
    comply with the terms of the GPLv2 license may obtain a commercial license
    before incorporating Reliance Edge into proprietary software for
    distribution in any form.  Visit http://www.datalight.com/reliance-edge for
    more information.
*/
/** @file
    @brief Implements certain shared methods for win32 command line tools.
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <redfs.h>
#include <redcoreapi.h>
#include <redvolume.h>

#include "wintlcmn.h"


/** @brief Convert a string into a volume number.

    In a POSIX-like configuration, @p pszVolume can either be a volume number or
    a volume path prefix.  In case of ambiguity, the volume number of a matching
    path prefix takes precedence.

    In an FSE configuration, @p pszVolume can be a volume number.

    @param pszVolume    The volume string.

    @return On success, returns the volume number; on failure, returns
            #REDCONF_VOLUME_COUNT.
*/
uint8_t FindVolumeNumber(
    const char     *pszVolume)
{
    unsigned long   ulNumber;
    const char     *pszEndPtr;
    uint8_t         bVolNum = REDCONF_VOLUME_COUNT;
  #if REDCONF_API_POSIX == 1
    uint8_t         bIndex;
  #endif

    /*  Determine if pszVolume can be interpreted as a volume number.
    */
    errno = 0;
    ulNumber = strtoul(pszVolume, (char **)&pszEndPtr, 10);
    if((errno == 0) && (ulNumber != ULONG_MAX) && (pszEndPtr[0U] == '\0') && (ulNumber < REDCONF_VOLUME_COUNT))
    {
        bVolNum = (uint8_t)ulNumber;
    }

  #if REDCONF_API_POSIX == 1
    /*  Determine if pszVolume is a valid path prefix.
    */
    for(bIndex = 0U; bIndex < REDCONF_VOLUME_COUNT; bIndex++)
    {
        if(strcmp(gaRedVolConf[bIndex].pszPathPrefix, pszVolume) == 0)
        {
            break;
        }
    }

    if(bIndex < REDCONF_VOLUME_COUNT)
    {
        /*  Edge case: It is technically possible for pszVolume to be both a
            valid volume number and a valid volume prefix, for different
            volumes.  For example, if pszVolume is "2", that would be recognized
            as volume number 2 above.  But if "2" is the (poorly chosen) path
            prefix for volume number 4, that would also be matched.  Since the
            POSIX-like API is primarily name based, and the ability to use
            volume numbers with this tool is just a convenience, the volume
            prefix takes precedence.
        */
        bVolNum = bIndex;

        printf("Info: Volume prefix \"%s\" matched with volume number %u\n", pszVolume, (unsigned)bVolNum);
    }
  #endif

    return bVolNum;
}


/** @brief Massage a drive name into a standardized format.

    @return pszDrive    The drive name to massage.

    @return Pointer to the massaged drive name.
*/
const char *MassageDriveName(
    const char *pszDrive)
{
    const char *pszRet;

    /*  If it looks like a drive letter followed by nothing else...
    */
    if(    (    ((pszDrive[0U] >= 'A') && (pszDrive[0U] <= 'Z'))
             || ((pszDrive[0U] >= 'a') && (pszDrive[0U] <= 'z')))
        && (pszDrive[1U] == ':')
        && (    (pszDrive[2U] == '\0')
             || ((pszDrive[2U] == '\\') && (pszDrive[3U] == '\0'))))
    {
        static char szBuffer[8U]; /* Big enough for "\\.\X:" */

        /*  Drives of the form "X:" or "X:\" are converted to "\\.\X:".
        */
        (void)strcpy(szBuffer, "\\\\.\\?:");
        szBuffer[4U] = pszDrive[0U];

        pszRet = szBuffer;
    }
    else
    {
        pszRet = pszDrive;
    }

    return pszRet;
}


/** @brief Determine if the argument is a help request.

    @param pszArgument  The argument to examine.

    @return Whether the argument is a help request.
*/
bool IsHelpRequest(
    const char *pszArgument)
{
    bool        fIsHelpRequest;

    if(    (strcmp(pszArgument, "?") == 0)
        || (strcmp(pszArgument, "/?") == 0)
        || (strcmp(pszArgument, "-?") == 0)
        || (_stricmp(pszArgument, "/h") == 0)
        || (_stricmp(pszArgument, "-h") == 0)
        || (_stricmp(pszArgument, "--help") == 0))
    {
        fIsHelpRequest = true;
    }
    else
    {
        fIsHelpRequest = false;
    }

    return fIsHelpRequest;
}


/** @brief Prompt the user to confirm an operation by typing in y or n.

    @param pszMessage   The message to show the user to prompt for input. The
                        string " [y/n] " is appended to the same line.

    @return Whether the user typed a y to confirm the operation.
*/
bool ConfirmOperation(
    const char *pszMessage)
{
    int iAnswer;
    int iChar;

    fprintf(stderr, "%s [y/n] ", pszMessage);
    fflush(stderr);

    while(true)
    {
        iAnswer = getchar();

        /*  Burn through the rest of the answer.  If the user typed
            "Affirmative", we don't want to complain twelve times.
        */
        iChar = iAnswer;
        while(iChar != '\n')
        {
            iChar = getchar();
        }

        if((iAnswer == 'y') || (iAnswer == 'Y') || (iAnswer == 'n') || (iAnswer == 'N'))
        {
            break;
        }

        fprintf(stderr, "Answer 'y' or 'n': ");
        fflush(stderr);
    }

    return ((iAnswer == 'y') || (iAnswer == 'Y'));
}

