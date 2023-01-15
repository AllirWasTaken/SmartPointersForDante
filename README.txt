biblioteka głownie używana do debugowania wycieków pamięci czy sprawdzania zachowania programu przy ograniczonej liczbie bajtów

Biblioteke można na bierząco dodawać i usuwać (includować) nie powinna ona zmienić działania programu w żaden sposób

Zredefiniowane funkcje(używać tak jak stare):
malloc
calloc
free
realloc

Dodatkowe funkcje
s_echo(int) - ustawia czy SmartPointers ma cokolwiek wypisywać na konsole
s_set_allocation_limit(size_t) - ustawia limit bajtów jaki program może zaalokować
s_free_all() - czyści wszystkie zaalokowane obszary pamięci
s_show_blocks() - Pokazuje aktualnie zaalokowane bloki w konsoli
s_status_of_allocation() - Pokazuje aktualny stan pamięci, Zajęte miejsce/Max miejsce

Program dodatkowo prócz wykrywania wycieków automatycznie wszystkie wycieki czyści, więc w konsekwencji tego nie trzeba
w ogóle w programie używać free, natomiast jest wskazane żeby nie nadużywać tego, czy też nie wrzucać tego wprost do dante
bo plagiat lub tłumaczenie się jak to działa

w main.c przykładowe użycie

jeśli jakaś dodatkowa funkcjonalność się przyda, lub jakiś bug jest znaleziony, śmiało pisać

Rozważam dodanie wykrywania/obsługi wycieków plików