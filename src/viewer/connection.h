/**
 * connection.h
 *
 * Used for the connection request structure.
 * @authors Florent Denef, Thomas Ducrot
 */

#ifndef SRC_CLIENT_CONNECTION_H_
#define SRC_CLIENT_CONNECTION_H_

typedef int16_t bool;
#define true 1
#define false 0

/**
 * Contains all of what is necessary to answer to the client.
 */
typedef struct {
	bool connection = false;
	int16_t sizeXTerm = 0;
	int16_t sizeYTerm = 0;
} connection_t;

#endif /* SRC_CLIENT_CONNECTION_H_ */
