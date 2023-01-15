biblioteka głownie używana do debugowania wycieków pamięci czy sprawdzania zachowania programu przy ograniczonej liczbie bajtów

Zredefiniowane funkcje(używać tak jak stare):
malloc
calloc
free
realloc

Dodatkowe funkcje
s_echo(int) - ustawia czy SmartPointers ma cokolwiek wypisywać na konsole
s_set_allocation_limit(size_t) - ustawia limit bajtów jaki program może zaalokować
s_free_all() - czyści wszystkie zaalokowane obszary pamięci

Program dodatkowo prócz wykrywania wycieków automatycznie wszystkie wycieki czyści, więc w konsekwencji tego nie trzeba
w ogóle w programie używać free, natomiast jest wskazane żeby nie nadużywać tego, czy też nie wrzucać tego wprost to dante
bo plagiat lub tłumaczenie się jak to działa