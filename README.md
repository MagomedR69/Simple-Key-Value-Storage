Simple Key-Value Storage — мини-хранилище «ключ-значение» на C
Упрощённый Redis: in-memory хеш-таблица

1. Функциональность
   Команда	Ответ
   `SET key value``OK`
   `GET key``VALUE <value>` / `NOT_FOUND`
   `DEL key``OK` / `NOT_FOUND`
   `EXISTS key``1` / `0`
   `COUNT`	число ключей
   Ошибки: `ERROR <описание>`, программа не падает.
   Расширения: append-only лог (replay при старте), TCP-сервер на `poll()` (одна строка = одна команда), опционально `EXPIRE key seconds`.
2. Технические требования
   C11, gcc/clang, Make, только libc + POSIX
   Флаги: `-Wall -Wextra -Wpedantic -Werror`
   Тесты под `-fsanitize=address,undefined`, valgrind без утечек
   Юнит-тесты на hashmap, parser, store
