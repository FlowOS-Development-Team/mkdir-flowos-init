#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Iterate through arguments to support: mkdir multiple times
    for (int i = 1; i < argc; i++) {
        // 0755 is standard (rwxr-xr-x)
        if (mkdir(argv[i], 0755) == -1) {
            fprintf(stderr, "Error creating '%s': %s\n", argv[i], strerror(errno));
            // Iterate to the next directory without errors causing kernel panics
        }
    }
    return 0;
}

//Copyright 2026 Elias Stinson (favoriteone)
// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
