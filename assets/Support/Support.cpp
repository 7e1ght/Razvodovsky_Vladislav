#include "Support.h"

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

bool utilities::kbhit()
{
    struct timeval        timeout;
    fd_set                readfds;
    int                how;

    /* look only at stdin (fd = 0) */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    /* poll: return immediately */
    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
    /* Change "&timeout" above to "(struct timeval *)0"       ^^^^^^^^
     * if you want to wait until a key is hit
     */

    if ((how > 0) && FD_ISSET(0, &readfds))
            return 1;
    else
            return 0;
}
