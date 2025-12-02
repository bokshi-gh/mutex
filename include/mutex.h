# pragma once

#include <stdatomic.h>

typedef struct {
	atomic_flag locked;
} mutex;

void mutex_init(mutex *m);
void mutex_lock(mutex *m);
void mutex_unlock(mutex *m);
