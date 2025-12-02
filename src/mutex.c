#include "mutex.h"

void mutex_init(mutex *m) {
	atomic_flag_clear(&m->locked);
}

void mutex_lock(mutex *m) {
	while (atomic_flag_test_and_set(&m->locked)) {}
}

void mutex_unlock(mutex *m) {
	atomic_flag_clear(&m->locked);
}
