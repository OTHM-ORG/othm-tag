#include <stdlib.h>

void *othm_tag_left_malloc(size_t tag, size_t tagged)
{
	return (((char *) malloc(tag + tagged)) + tag);
}
