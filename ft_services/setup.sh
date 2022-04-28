kubectl get pods
if [ $? != 1 ]
then
	kubectl delete all --all --all-namespaces
	minikube delete
fi

echo "user42\nuser42" | sudo -S chmod 666 /var/run/docker.sock > /dev/null

# Start Minikube
minikube start --vm-driver=docker


# Delete all docker images
eval $(minikube docker-env)
echo "\nDeleting all docker images...\n" ; echo y | docker system prune -a > /dev/null


#________________METALLB___________________

# Setup Metallb
echo "\nStarting Loadblancer..." ; sh srcs/metallb/metallb.sh > /dev/null



#_________________VOLUME__________________

# Prepare volume
echo "\n\nBuilding Volume...\n" 
kubectl apply -f srcs/volume/influxdb-pv-claim.yaml > /dev/null
kubectl apply -f srcs/volume/influxdb-pv-volume.yaml > /dev/null
kubectl apply -f srcs/volume/mysql-pv-claim.yaml > /dev/null
kubectl apply -f srcs/volume/mysql-pv-volume.yaml > /dev/null



#__________________IMAGES__________________

# build all images
echo "\n\nBuilding images\n"
echo "-> Mysql-image created" ; docker build -t mysql-image srcs/mysql/ > /dev/null
echo "-> Nginx-image created" ; docker build -t nginx-image srcs/nginx/ > /dev/null
echo "-> Wordpress-image created" ; docker build -t wordpress-image srcs/wordpress/ > /dev/null
echo "-> Phpmyadmin-image created" ; docker build -t phpmyadmin-image srcs/phpmyadmin/ > /dev/null
echo "-> Grafana-image created" ; docker build -t grafana-image srcs/grafana/ > /dev/null
echo "-> InfluxDB-image created" ; docker build -t influxdb-image srcs/influxdb/ > /dev/null
echo "-> Ftps-image created" ; docker build -t ftps-image srcs/ftps/ > /dev/null



#________________CONTAINERS________________

# deploy pods and services
echo "\n\nCreating Services & Pods...\n"
echo "Mysql created" ; kubectl apply -f srcs/mysql/mysql-deployment.yaml > /dev/null
echo "Wordpress created" ; kubectl apply -f srcs/wordpress/wordpress-deployment.yaml > /dev/null
echo "Phpmyadmin created" ; kubectl apply -f srcs/phpmyadmin/phpmyadmin-deployment.yaml > /dev/null
echo "Nginx created" ; kubectl apply -f srcs/nginx/nginx-deployment.yaml > /dev/null
echo "Ftps created" ; kubectl apply -f srcs/ftps/ftps-deployment.yaml > /dev/null
echo "InfluxDB created" ; kubectl apply -f srcs/influxdb/influxdb-deployment.yaml > /dev/null
echo "Grafana created" ; kubectl apply -f srcs/grafana/grafana-deployment.yaml > /dev/null

#___________________END_____________________

echo "\n\n\n\n\nWELL DONE BROW\n\n\n\n\n"

kubectl get all -o wide
