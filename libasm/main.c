#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>

size_t		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char * dst, const char * src);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, const void *buf, size_t nbyte);
char *ft_strdup(const char *s1);

void test_strcpy(char *ok3)
{
	printf("//////////TESTS STRCPY//////////\n");
	ok3 = malloc(sizeof(char) * 5 + 1);
	printf("%s\n", ft_strcpy(ok3, "abcd"));
	printf("%s\n", ok3);
	free(ok3);
	ok3 = malloc(sizeof(char) * 83 + 1);
	printf("%s\n", ft_strcpy(ok3, "Ligue des Champions : Barcelone - Paris SG\nSans Neymar ni Di Maria, comment faire ?"));
	printf("%s\n", ok3);
	free(ok3);
	ok3 = malloc(sizeof(char) * 1);
	printf("%s\n", ft_strcpy(ok3, ""));
	printf("%s\n", ok3);
	ok3 = malloc(sizeof(char) * 7);
	printf("%s\n", ft_strcpy(ok3, "ah\0\0\0l"));
	printf("%s\n", ok3);
	free(ok3);
}

void test_strlen(void)
{
	char *adam;

	adam = "Adam a longtemps été fier de son père, un braqueur de l'ancienne école. Très vite, lui qui voulait marcher sur ses traces constate que la vie de voyou nest pas héréditaire.";
	printf("//////////TESTS STRLEN//////////\n");
	printf("hello : %zu\n", ft_strlen("hello"));
	printf(" : %zu\n", ft_strlen(""));
	printf("%s : %zu / %zu\n", adam, ft_strlen(adam), strlen(adam));

}

void test_strcmp(void)
{
	char *str1;
	char *str2;
	char *strnull;
	char *strweird;
	char *str0;

	str1 = "abcd";
	str2 = "abricotiers";
	strweird = "^àç!è§('ç!àé";
	str0 = "";
	printf("//////////TESTS STRCMP//////////\n");
	printf("%s et %s : %d / %d\n", str0, str0, strcmp(str0, str0), ft_strcmp(str0, str0));
	printf("%s et %s : %d / %d\n", str1, str1, strcmp(str1, str1), ft_strcmp(str1, str1));
	printf("%s et %s : %d / %d\n", str2, str1, strcmp(str2, str1), ft_strcmp(str2, str1));
	printf("%s et %s : %d / %d\n", str1, str2, strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("%s et %s : %d / %d\n", str2, strweird, strcmp(str2, strweird), ft_strcmp(str2, strweird));
	printf("%s et %s : %d / %d\n", strweird + 5, strweird + 6, strcmp(strweird + 5, strweird + 6), ft_strcmp(strweird + 5, strweird + 6));
}

void test_strdup(void)
{
	char *str;

	printf("//////////TESTS STRDUP//////////\n");
	str = ft_strdup("Découvrez le Nouveau SUV MINI COUNTRYMAN Édition suréquipée Northwood. Place à toutes vos passions.");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("⚡️ L'AMOUR TRANQUILLE ⚡️\nA tous les coeurs inquiets, à l'amour ⚡️⚡️\nFêtons le tout le temps ⏳ #lamourtranquille #saintvalentin");
	printf("%s\n", str);
	free(str);
	str = ft_strdup(NULL);
	printf("%s\n", str);
	free(str);
}

void test_write(void)
{
	int fd;
	char *txt;

	printf("//////////TESTS WRITE//////////\n");
	ft_write(1, "ok\n", 3);
	printf("***Creation d'un ficher test out_write\n");
	fd = open("out_write", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("***Ecriture puis lecture\n");
	txt = "Extraire la texture d'un jean denim dans les moindres détails pour la transformer en un filtre 3d, c'est technique. Alors pour la sortie de la nouvelle collection responsable Lee Jeans Europe et H&M, Nassim Bouaza et Meric Chaperon du studio Plus Mûrs nous montre tout. Le filtre est à essayer sur notre Insta\n";
	ft_write(fd, txt, ft_strlen(txt));
	system("cat out_write");
	close(fd);
	printf("***Fermeture du fichier\n");
	printf("errno avant write dans fd ferme : %d\n", errno);
	ft_write(fd, "euh", 3);
	printf("errno apres %d : %s\n", errno, strerror(errno));
	errno = 0;
}

void test_read(void)
{
	char *red;
	int fd;

	printf("//////////TESTS READ//////////\n");
	printf("***Ecrire un texte de 10 caractères, création fichier out_read\n");
	red = malloc(12);
	ft_read(0, red, 11);
	red[12] = '\0';
	printf("%s", red);
	fd = open("out_read", O_RDWR | O_TRUNC | O_CREAT, 0777);
	ft_write(fd, red, 11);
	printf("***Lecture à partir du fichier out_read\n");
	ft_read(fd, red, 11);
	red[12] = '\0';
	printf("%s", red);
	printf("***Fermeture du fichier\n");
	close(fd);
	fd = open("out_write", O_RDONLY, 0777);
	printf("**Lecture à partir du fichier out_write\n");
	ft_read(fd, red, 11);
	red[12] = '\0';
	printf("%s\n", red);
	printf("**Fermeture du fichier\n");
	close(fd);
	printf("errno avant read dans fd ferme : %d\n", errno);
	ft_read(fd, red, 11);
	printf("errno apres %d : %s\n", errno, strerror(errno));
	free(red);
	errno = 0;
}
 
int main(void)
{
	char *ok3;

	test_strcmp();
	test_strlen();
	test_strcpy(ok3);
	test_strdup();
	test_write();
	test_read();
}
