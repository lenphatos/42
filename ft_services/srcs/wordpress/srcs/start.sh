while (true) do
	service telegraf status
	if [ $? != 0 ]
	then
		service telegraf restart
	fi

	service php-fpm7 status
        if [ $? != 0 ]
        then
		service php-fpm7 restart
        fi
done
