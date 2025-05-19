#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

void keyboardInit();
void keyboardDestroy();
int keyhit();
int readch();

#ifdef __cplusplus
}
#endif

#endif /* __KEYBOARD_H__ */