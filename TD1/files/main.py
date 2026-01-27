import subprocess


def execution(listCmd):
    cpt = 1
    for cmd in listCmd:
        print("Test : ", cpt)
        cpt+=1

        try:
            resultat = subprocess.run(cmd, shell=True, capture_output=True, text=True)
            print(resultat.stdout.strip())
        except Exception as e:
            print("Execption : ", e)


listCmd = [

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
    r'''find . -name simple.c -exec bash -c "gcc -Werror {} && ./a.out >out.txt && grep -q 'Youpi \!$' out.txt && grep -q 'Super' out.txt && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort'''
   ]

if __name__ == "__main__":
    execution(listCmd)
