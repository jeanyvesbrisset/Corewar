#!/bin/sh
i=0
clear
make -sj

echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Gagnant\n"
    ./asm vm_champs/valid/Gagnant.s
cp vm_champs/valid/Gagnant.cor notre
./vm_champs/asm vm_champs/valid/Gagnant.s
cp vm_champs/valid/Gagnant.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi


read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n _honeybadger\n"
    ./asm vm_champs/valid/_honeybadger.s
cp vm_champs/valid/_honeybadger.cor notre
./vm_champs/asm vm_champs/valid/_honeybadger.s
cp vm_champs/valid/_honeybadger.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n 42\n"
    ./asm vm_champs/valid/42.s
cp vm_champs/valid/42.cor notre
./vm_champs/asm vm_champs/valid/42.s
cp vm_champs/valid/42.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n aff_no_OCP\n"
    ./asm vm_champs/valid/aff_no_OCP.s
cp vm_champs/valid/aff_no_OCP.cor notre
./vm_champs/asm vm_champs/valid/aff_no_OCP.s
cp vm_champs/valid/aff_no_OCP.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Asombra\n"
    ./asm vm_champs/valid/Asombra.s
cp vm_champs/valid/Asombra.cor notre
./vm_champs/asm vm_champs/valid/Asombra.s
cp vm_champs/valid/Asombra.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n barriere\n"
    ./asm vm_champs/valid/barriere.s
cp vm_champs/valid/barriere.cor notre
./vm_champs/asm vm_champs/valid/barriere.s
cp vm_champs/valid/barriere.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n bee_gees\n"
    ./asm vm_champs/valid/bee_gees.s
cp vm_champs/valid/bee_gees.cor notre
./vm_champs/asm vm_champs/valid/bee_gees.s
cp vm_champs/valid/bee_gees.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n bigzork\n"
    ./asm vm_champs/valid/bigzork.s
cp vm_champs/valid/bigzork.cor notre
./vm_champs/asm vm_champs/valid/bigzork.s
cp vm_champs/valid/bigzork.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n car\n"
    ./asm vm_champs/valid/car.s
cp vm_champs/valid/car.cor notre
./vm_champs/asm vm_champs/valid/car.s
cp vm_champs/valid/car.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n casimir\n"
    ./asm vm_champs/valid/casimir.s
cp vm_champs/valid/casimir.cor notre
./vm_champs/asm vm_champs/valid/casimir.s
cp vm_champs/valid/casimir.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n champ\n"
    ./asm vm_champs/valid/champ.s
cp vm_champs/valid/champ.cor notre
./vm_champs/asm vm_champs/valid/champ.s
cp vm_champs/valid/champ.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n comment_len_2048\n"
    ./asm vm_champs/valid/comment_len_2048.s
cp vm_champs/valid/comment_len_2048.cor notre
./vm_champs/asm vm_champs/valid/comment_len_2048.s
cp vm_champs/valid/comment_len_2048.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n corelol\n"
    ./asm vm_champs/valid/corelol.s
cp vm_champs/valid/corelol.cor notre
./vm_champs/asm vm_champs/valid/corelol.s
cp vm_champs/valid/corelol.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n darksasuke\n"
    ./asm vm_champs/valid/darksasuke.s
cp vm_champs/valid/darksasuke.cor notre
./vm_champs/asm vm_champs/valid/darksasuke.s
cp vm_champs/valid/darksasuke.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
DIFF=$(diff notre vrai)
if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n doge\n"
    ./asm vm_champs/valid/doge.s
cp vm_champs/valid/doge.cor notre
./vm_champs/asm vm_champs/valid/doge.s
cp vm_champs/valid/doge.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi


read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Douceur_power\n"
    ./asm vm_champs/valid/Douceur_power.s
cp vm_champs/valid/Douceur_power.cor notre
./vm_champs/asm vm_champs/valid/Douceur_power.s
cp vm_champs/valid/Douceur_power.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n dubo\n"
    ./asm vm_champs/valid/dubo.s
cp vm_champs/valid/dubo.cor notre
./vm_champs/asm vm_champs/valid/dubo.s
cp vm_champs/valid/dubo.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n empty_namecomment\n"
    ./asm vm_champs/valid/empty_namecomment.s
cp vm_champs/valid/empty_namecomment.cor notre
./vm_champs/asm vm_champs/valid/empty_namecomment.s
cp vm_champs/valid/empty_namecomment.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n end_comment\n"
    ./asm vm_champs/valid/end_comment.s
cp vm_champs/valid/end_comment.cor notre
./vm_champs/asm vm_champs/valid/end_comment.s
cp vm_champs/valid/end_comment.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n ex\n"
    ./asm vm_champs/valid/ex.s
cp vm_champs/valid/ex.cor notre
./vm_champs/asm vm_champs/valid/ex.s
cp vm_champs/valid/ex.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n ex1\n"
    ./asm vm_champs/valid/ex1.s
cp vm_champs/valid/ex1.cor notre
./vm_champs/asm vm_champs/valid/ex1.s
cp vm_champs/valid/ex1.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Explosive_Kitty\n"
    ./asm vm_champs/valid/Explosive_Kitty.s
cp vm_champs/valid/Explosive_Kitty.cor notre
./vm_champs/asm vm_champs/valid/Explosive_Kitty.s
cp vm_champs/valid/Explosive_Kitty.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n flipped_name_comment\n"
    ./asm vm_champs/valid/flipped_name_comment.s
cp vm_champs/valid/flipped_name_comment.cor notre
./vm_champs/asm vm_champs/valid/flipped_name_comment.s
cp vm_champs/valid/flipped_name_comment.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n fluttershy\n"
    ./asm vm_champs/valid/fluttershy.s
cp vm_champs/valid/fluttershy.cor notre
./vm_champs/asm vm_champs/valid/fluttershy.s
cp vm_champs/valid/fluttershy.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n gateau\n"
    ./asm vm_champs/valid/gateau.s
cp vm_champs/valid/gateau.cor notre
./vm_champs/asm vm_champs/valid/gateau.s
cp vm_champs/valid/gateau.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n gedeon\n"
    ./asm vm_champs/valid/gedeon.s
cp vm_champs/valid/gedeon.cor notre
./vm_champs/asm vm_champs/valid/gedeon.s
cp vm_champs/valid/gedeon.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n hash_and_tab_at_EOF\n"
    ./asm vm_champs/valid/hash_and_tab_at_EOF.s
cp vm_champs/valid/hash_and_tab_at_EOF.cor notre
./vm_champs/asm vm_champs/valid/hash_and_tab_at_EOF.s
cp vm_champs/valid/hash_and_tab_at_EOF.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n hash_at_header\n"
    ./asm vm_champs/valid/hash_at_header.s
cp vm_champs/valid/hash_at_header.cor notre
./vm_champs/asm vm_champs/valid/hash_at_header.s
cp vm_champs/valid/hash_at_header.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n helltrain\n"
    ./asm vm_champs/valid/helltrain.s
cp vm_champs/valid/helltrain.cor notre
./vm_champs/asm vm_champs/valid/helltrain.s
cp vm_champs/valid/helltrain.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n jinx\n"
    ./asm vm_champs/valid/jinx.s
cp vm_champs/valid/jinx.cor notre
./vm_champs/asm vm_champs/valid/jinx.s
cp vm_champs/valid/jinx.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n jumper\n"
    ./asm vm_champs/valid/jumper.s
cp vm_champs/valid/jumper.cor notre
./vm_champs/asm vm_champs/valid/jumper.s
cp vm_champs/valid/jumper.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n justin_bee\n"
    ./asm vm_champs/valid/justin_bee.s
cp vm_champs/valid/justin_bee.cor notre
./vm_champs/asm vm_champs/valid/justin_bee.s
cp vm_champs/valid/justin_bee.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Kappa\n"
    ./asm vm_champs/valid/Kappa.s
cp vm_champs/valid/Kappa.cor notre
./vm_champs/asm vm_champs/valid/Kappa.s
cp vm_champs/valid/Kappa.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Kittystrophic\n"
    ./asm vm_champs/valid/Kittystrophic.s
cp vm_champs/valid/Kittystrophic.cor notre
./vm_champs/asm vm_champs/valid/Kittystrophic.s
cp vm_champs/valid/Kittystrophic.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n littlepuppy\n"
    ./asm vm_champs/valid/littlepuppy.s
cp vm_champs/valid/littlepuppy.cor notre
./vm_champs/asm vm_champs/valid/littlepuppy.s
cp vm_champs/valid/littlepuppy.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n live\n"
    ./asm vm_champs/valid/live.s
cp vm_champs/valid/live.cor notre
./vm_champs/asm vm_champs/valid/live.s
cp vm_champs/valid/live.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n loose\n"
    ./asm vm_champs/valid/loose.s
cp vm_champs/valid/loose.cor notre
./vm_champs/asm vm_champs/valid/loose.s
cp vm_champs/valid/loose.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Machine-gun\n"
    ./asm vm_champs/valid/Machine-gun.s
cp vm_champs/valid/Machine-gun.cor notre
./vm_champs/asm vm_champs/valid/Machine-gun.s
cp vm_champs/valid/Machine-gun.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

rm -Rf notre vrai
rm -Rf vm_champs/valid/*.cor

echo "\n mandragore\n"
    ./asm vm_champs/valid/mandragore.s
cp vm_champs/valid/mandragore.cor notre
./vm_champs/asm vm_champs/valid/mandragore.s
cp vm_champs/valid/mandragore.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n MarineKing\n"
    ./asm vm_champs/valid/MarineKing.s
cp vm_champs/valid/MarineKing.cor notre
./vm_champs/asm vm_champs/valid/MarineKing.s
cp vm_champs/valid/MarineKing.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n maxidef\n"
    ./asm vm_champs/valid/maxidef.s
cp vm_champs/valid/maxidef.cor notre
./vm_champs/asm vm_champs/valid/maxidef.s
cp vm_champs/valid/maxidef.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n meowluigi\n"
    ./asm vm_champs/valid/meowluigi.s
cp vm_champs/valid/meowluigi.cor notre
./vm_champs/asm vm_champs/valid/meowluigi.s
cp vm_champs/valid/meowluigi.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Misaka_Mikoto\n"
    ./asm vm_champs/valid/Misaka_Mikoto.s
cp vm_champs/valid/Misaka_Mikoto.cor notre
./vm_champs/asm vm_champs/valid/Misaka_Mikoto.s
cp vm_champs/valid/Misaka_Mikoto.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n mise_a_jour_windows95\n"
    ./asm vm_champs/valid/mise_a_jour_windows95.s
cp vm_champs/valid/mise_a_jour_windows95.cor notre
./vm_champs/asm vm_champs/valid/mise_a_jour_windows95.s
cp vm_champs/valid/mise_a_jour_windows95.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n mortel\n"
    ./asm vm_champs/valid/mortel.s
cp vm_champs/valid/mortel.cor notre
./vm_champs/asm vm_champs/valid/mortel.s
cp vm_champs/valid/mortel.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n name_len_128\n"
    ./asm vm_champs/valid/name_len_128.s
cp vm_champs/valid/name_len_128.cor notre
./vm_champs/asm vm_champs/valid/name_len_128.s
cp vm_champs/valid/name_len_128.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n neg_indirect_error\n"
    ./asm vm_champs/valid/neg_indirect_error.s
cp vm_champs/valid/neg_indirect_error.cor notre
./vm_champs/asm vm_champs/valid/neg_indirect_error.s
cp vm_champs/valid/neg_indirect_error.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n nl_at_header_flipped\n"
    ./asm vm_champs/valid/nl_at_header_flipped.s
cp vm_champs/valid/nl_at_header_flipped.cor notre
./vm_champs/asm vm_champs/valid/nl_at_header_flipped.s
cp vm_champs/valid/nl_at_header_flipped.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n nl_at_header\n"
    ./asm vm_champs/valid/nl_at_header.s
cp vm_champs/valid/nl_at_header.cor notre
./vm_champs/asm vm_champs/valid/nl_at_header.s
cp vm_champs/valid/nl_at_header.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n no_space_between_op_and_param\n"
    ./asm vm_champs/valid/no_space_between_op_and_param.s
cp vm_champs/valid/no_space_between_op_and_param.cor notre
./vm_champs/asm vm_champs/valid/no_space_between_op_and_param.s
cp vm_champs/valid/no_space_between_op_and_param.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Octobre_Rouge_V4.2\n"
    ./asm vm_champs/valid/Octobre_Rouge_V4.2.s
cp vm_champs/valid/Octobre_Rouge_V4.2.cor notre
./vm_champs/asm vm_champs/valid/Octobre_Rouge_V4.2.s
cp vm_champs/valid/Octobre_Rouge_V4.2.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n overwatch\n"
    ./asm vm_champs/valid/overwatch.s
cp vm_champs/valid/overwatch.cor notre
./vm_champs/asm vm_champs/valid/overwatch.s
cp vm_champs/valid/overwatch.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Rainbow_dash\n"
    ./asm vm_champs/valid/Rainbow_dash.s
cp vm_champs/valid/Rainbow_dash.cor notre
./vm_champs/asm vm_champs/valid/Rainbow_dash.s
cp vm_champs/valid/Rainbow_dash.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n run_Kitty_RUN\n"
    ./asm vm_champs/valid/run_Kitty_RUN.s
cp vm_champs/valid/run_Kitty_RUN.cor notre
./vm_champs/asm vm_champs/valid/run_Kitty_RUN.s
cp vm_champs/valid/run_Kitty_RUN.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n salamahenagalabadoun\n"
    ./asm vm_champs/valid/salamahenagalabadoun.s
cp vm_champs/valid/salamahenagalabadoun.cor notre
./vm_champs/asm vm_champs/valid/salamahenagalabadoun.s
cp vm_champs/valid/salamahenagalabadoun.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n sam_2.0\n"
    ./asm vm_champs/valid/sam_2.0.s
cp vm_champs/valid/sam_2.0.cor notre
./vm_champs/asm vm_champs/valid/sam_2.0.s
cp vm_champs/valid/sam_2.0.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n skynet\n"
    ./asm vm_champs/valid/skynet.s
cp vm_champs/valid/skynet.cor notre
./vm_champs/asm vm_champs/valid/skynet.s
cp vm_champs/valid/skynet.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n slider2\n"
    ./asm vm_champs/valid/slider2.s
cp vm_champs/valid/slider2.cor notre
./vm_champs/asm vm_champs/valid/slider2.s
cp vm_champs/valid/slider2.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n sq_at_header\n"
    ./asm vm_champs/valid/sq_at_header.s
cp vm_champs/valid/sq_at_header.cor notre
./vm_champs/asm vm_champs/valid/sq_at_header.s
cp vm_champs/valid/sq_at_header.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Survivor\n"
    ./asm vm_champs/valid/Survivor.s
cp vm_champs/valid/Survivor.cor notre
./vm_champs/asm vm_champs/valid/Survivor.s
cp vm_champs/valid/Survivor.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n tab_at_end_of_file\n"
    ./asm vm_champs/valid/tab_at_end_of_file.s
cp vm_champs/valid/tab_at_end_of_file.cor notre
./vm_champs/asm vm_champs/valid/tab_at_end_of_file.s
cp vm_champs/valid/tab_at_end_of_file.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n terminator\n"
    ./asm vm_champs/valid/terminator.s
cp vm_champs/valid/terminator.cor notre
./vm_champs/asm vm_champs/valid/terminator.s
cp vm_champs/valid/terminator.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n THUNDER\n"
    ./asm vm_champs/valid/THUNDER.s
cp vm_champs/valid/THUNDER.cor notre
./vm_champs/asm vm_champs/valid/THUNDER.s
cp vm_champs/valid/THUNDER.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n toto\n"
    ./asm vm_champs/valid/toto.s
cp vm_champs/valid/toto.cor notre
./vm_champs/asm vm_champs/valid/toto.s
cp vm_champs/valid/toto.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n turtle\n"
    ./asm vm_champs/valid/turtle.s
cp vm_champs/valid/turtle.cor notre
./vm_champs/asm vm_champs/valid/turtle.s
cp vm_champs/valid/turtle.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n ultima\n"
    ./asm vm_champs/valid/ultima.s
cp vm_champs/valid/ultima.cor notre
./vm_champs/asm vm_champs/valid/ultima.s
cp vm_champs/valid/ultima.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n ultimate-surrender\n"
    ./asm vm_champs/valid/ultimate-surrender.s
cp vm_champs/valid/ultimate-surrender.cor notre
./vm_champs/asm vm_champs/valid/ultimate-surrender.s
cp vm_champs/valid/ultimate-surrender.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Varimathras\n"
    ./asm vm_champs/valid/Varimathras.s
cp vm_champs/valid/Varimathras.cor notre
./vm_champs/asm vm_champs/valid/Varimathras.s
cp vm_champs/valid/Varimathras.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n Wall\n"
    ./asm vm_champs/valid/Wall.s
cp vm_champs/valid/Wall.cor notre
./vm_champs/asm vm_champs/valid/Wall.s
cp vm_champs/valid/Wall.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n weirdest_error_ever\n"
    ./asm vm_champs/valid/weirdest_error_ever.s
cp vm_champs/valid/weirdest_error_ever.cor notre
./vm_champs/asm vm_champs/valid/weirdest_error_ever.s
cp vm_champs/valid/weirdest_error_ever.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n youforkmytralala\n"
    ./asm vm_champs/valid/youforkmytralala.s
cp vm_champs/valid/youforkmytralala.cor notre
./vm_champs/asm vm_champs/valid/youforkmytralala.s
cp vm_champs/valid/youforkmytralala.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))

echo "\n zork\n"
    ./asm vm_champs/valid/zork.s
cp vm_champs/valid/zork.cor notre
./vm_champs/asm vm_champs/valid/zork.s
cp vm_champs/valid/zork.cor vrai
vim -c "%!xxd" -c wq notre
vim -c "%!xxd" -c wq vrai
 if [ "$DIFF" != "" ]
then
	echo "\n\n\033[31mIl y a DIFF\n\n\033[00m"
	diff notre vrai
	echo "\n\n"
	mv notre "notre-error-$i"
	mv vrai "vrai-error-$i"
fi

read -p "Appuyez sur une touche pour continuer... " TOUCH
rm -Rf notre vrai
echo "\ntest numero : $i\n"
i=$((i+1))
