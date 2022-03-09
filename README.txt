Mai intai am crea clasa "PLAYER" in care am supradefinit operatorii de citire, respectivi scriere, necesari pentru citirea datelor din fisier.
De asemenea, am realizat un get-er pentru a intoarce punctajul unui jucator, dar si un set-er pentru a putea modifica punctajul acestuia.

Aceasta clasa am inclus-o in clasa ECHIPA care contine, pe celelalte atribute, un vector de playeri(pointer, initail null). Am supradefinit aici
operatorul >>,<<(corespuncatori pentru citirea datelor din fisier),dar si operatorul =.Vectorul de playeri este alocat odata cu citirea dateor din 
fisier si aflarea numarului de jucatori din echipa respectiva.De asemenea, am implementat mai multi set-eri si get-eri, pentru modificarea sau aflarea
anumitor atribute ale aceste clase.

Apoi am creat o clasa LISTA cu un atribut de tip echipa si un atriput de tip lista *urmator. Mai departe am creat o functie lista_init() care creaza 
o lista cu informatiile din fisier. Apoi, pentru eliminarea anumitor echipe din lista, am creat o functie eliminare_element, care elimina un singur
element din aceasta(element primit ca parametru). Am creat o functie eliminare_toate(), care afla echipele din lista cu cel mai mic punctaj, si,
pe baza acestor rezultate, apeleaza fuctia eliminare_element() pentru a elimina elementul respectiv pana la ramanerea in lista a numarului dorit de echipe.

De asemenea, am mai realizat get-er pentru echipa, precum si o functie de afisare pentru lista.

Apoi am creat clasa MECI, in care am atributele, echipa 1, echipa 2 si pointerul catre urmatorul element de tip meci, precum si metode set-er si get-er.

Am creat o clasa StivaInvingatori si o clasa StivaPierzatori.(atribute= un element de tip echipa si un pointer catre urmatorul elment). In aceasta am inclus metode de
populare a stivei, precum si de stergere si afisare.

In clasa COADA am inclus clasa meci. In functia populeaza_coada(), care primeste ca parametrii coada declarata in main si lista de echipe, am construi meciurile
prin inserarea a cate doua echipe, iar in coada am inserat aceste meciuri dintre echipe. In functia creare_stiva(), se primesc ca parametri stiva de invingatori,
stiva de castigatori, precum si coada din care se vor extragea acestea. In aceasta functie parcurg meciurile din coada si in functie de punctajele acestora(echiap 1 si 2)
le inserez in stiva de castigatori sau de pierzatori cu ajurorul functiilor adauga_invingatori() sau adauga_pierzatori()(Aceste functii fac parte din clasele sticelor de 
mai sus, functii care primesc ca parametru pointerul la stiva respectiva si echipa dorita a fi introdusa in stiva aceea). Functia repopuleaza_coada() face acelasi lucru ca
functia populeaza_coada(), doar ca , aceasta introduce elemente in coada nu din lista initiala, ci din stiva creata mai sus. De asmemena, am realizat set-ere, get-ere, precum 
si functii pentru afisarea, respectiv stergrea cozii.

Am creat o clasa BST pentru realizarea arborelui binar de cautare. Functia creare_arbore_BST primeste ca parametru o stiva si o parcurge pe aceasta pana la final. Pentru
fiecare element al stivei, functia apeleaza o alta functie(care primeste echipa scoasa din stiva ca parametr), functie care introduce elementul respectiv in arbore. De 
asemene, am realizat o functie de afisare a Arborelui, precum si o functie pentru stergerea lui.

Am creat clasa AVL pentru realizarea arborelui AVL. Aici, metodele creare_arbore_AVL() si insert() functioneaza foarte asemanator cu cele de la BST. Pe langa acestea, am
mai facut cateva functii necesare echilibrarii arorelui AVL.

MAIN:
Declar o lista, o populez cu elemente de tip echipa din fisier cu ajutorul functieei lista_Inint(), creez coaada initiala cu elemnete din lista cu ajuorul functiei 
populeaza_coada si elimin elemntele in plus cu functia eliminare_toate().Pentru exercitiul 3, repet operatiile de creare stive, repopulare coada(din stiva de echipe
castigatoare) pana cand raman doar cu un meci in coada. In plus, in momentul in care in coada mea raman doar cu 8 meciuri, repopulez stiva de invingatori si pe aceasta
o transmit ca parametru pentru functiile creare_arbore_BST si creare_arbore_AVL.
Se realizeaza afisarea si in final se elibereaza memoria.




