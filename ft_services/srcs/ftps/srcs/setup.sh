# telegraf
openrc
touch /run/openrc/softlevel
service telegraf start

set -x # Print commands and their arguments as they are executed
mkdir -p /srcs/ftp/ftpuser
echo -e "ftpass\nftpass" | adduser -h /srcs/ftp/ftpuser ftpuser
chown ftpuser:ftpuser /srcs/ftp/ftpuser
mkdir /srcs/ftp/ftpuser/folder_text
chown ftpuser:ftpuser /srcs/ftp/ftpuser/folder_text
touch /srcs/ftp/ftpuser/folder_text/text.txt

exec /usr/sbin/vsftpd -opasv_min_port=21000 -opasv_max_port=21004 -opasv_address=172.17.0.233 /etc/vsftpd/vsftpd.conf & tail -f /dev/null
