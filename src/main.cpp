#include <stdio.h>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int main(int argc, char **argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "script.lua");
    lua_getglobal(L, "saudacao");
    lua_pushstring(L,"Desenvolvedor");
    lua_pcall(L,1,1,0);
    const char *resultado = lua_tostring(L,-1);
    printf("Resultado do lua: %s\n", resultado);
    lua_pop(L,1);

    lua_close(L);

    return 0;
}
