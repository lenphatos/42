kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml > /dev/null
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml > /dev/null

if [ "$(kubectl get secrets --namespace metallb-system | grep memberlist)" = "" ]
then
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" > /dev/null
fi

kubectl apply -f ./srcs/metallb/metallb-config.yaml > /dev/null

