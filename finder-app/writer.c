#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Error: Two arguments required. Usage: %s <writefile> <writestr>\n", argv[0]);
		exit(1);
	}



	const char *writefile = argv[1];
	const char *writestr = argv[2];

	// setup facility code for log message as per #3
	openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

	FILE *file = fopen(writefile, "w");

	// writer utility does not create dir which do not exist.
	if (file == NULL) {
		// error logging as per #3
		syslog(LOG_ERR, "Error: Could not create file %s", writefile);
		fprintf(stderr, "Error: Could not create file %s\n", writefile);
		closelog();
		exit(1);
	}

	fprintf(file, "%s", writestr);

	// instr #3
	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

	fclose(file);

	closelog();

	printf("File %s created  with content: %s\n", writefile, writestr);
	return 0;
}

