import subprocess


def execution(AlllistCmd):
    cpt = 1
    cpt2 = 1
    for packCmd in AlllistCmd:
        print("-----------------TD : ", cpt2, "-----------------")
        cpt2 += 1
        for cmd in packCmd:
            print("Test : ", cpt)
            cpt+=1

            try:
                resultat = subprocess.run(cmd, shell=True, capture_output=True, text=True)
                print(resultat.stdout.strip())
            except Exception as e:
                print("Execption : ", e)
        print("\n")


listCmd = [

    #--------TD1---------#
    [
        # jeu. 22 janv. 21:45
        r'''find . -name simple.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 23 janv. 12:12
        r'''find . -name main-et-dbl.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 26 janv. 09:36
        r'''find . -name main-cent-premiers.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 09:40
        r'''find . -name main-ni-par-3-ni-par-7.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 11:48
        r'''find . -name lngcha.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 12:31
        r'''find . -name palindrome.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 14:22
        r'''find . -name age_total.c -exec bash -c "gcc -c {} -I. && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 14:38
        r'''find . -name simple.c -exec bash -c "gcc -Werror {} && ./a.out >out.txt && grep -q 'Youpi \!$' out.txt && grep -q 'Super' out.txt && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mer. 28 janv. 22:30
        r'''find . -name main-et-dbl.c -exec bash -c "gcc -Werror {} && (./a.out | grep -q 'résultat: 8' && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        #   mer. 28 janv. 22:53
        r'''find . -name main-cent-premiers.c -exec bash -c "gcc -Werror {} && (./a.out | grep -e '^1 2 3 4 5' | grep -q '96 97 98 99 100[ ]$' && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort''',
    ],


    #--------TD2---------#
    [
        # mer. 28 janv. 22:47
        r'''	find . -name maximum.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \; | sort''',
    ],
   ]

if __name__ == "__main__":
    execution(listCmd)
