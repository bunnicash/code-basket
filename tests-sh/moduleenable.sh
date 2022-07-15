#!/bin/bash

## Config-land
init_sys="systemd"  # either "openrc" or anything else... "systemd"

## Installer
modules="dhcpcd.service NetworkManager.service fstrim.timer"

init_enable () {
    for module in $modules; do
        echo "$init_1 $module"
    done
    echo " "
}

if [ $init_sys == "openrc" ]; then  # adds to "default" runlevel
    init_1="rc-update add" && init_enable
else init_1="systemctl enable" && init_enable  # systemd doesn't really need the .service typed out
fi
