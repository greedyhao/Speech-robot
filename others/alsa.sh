mkdir /dev/snd
cd /dev/snd
mknod dsp c 14 3
mknod audio c 14 4
mknod mixer c 14 0
mknod controlC0 c 116 0
mknod seq c 116 1
mknod pcmC0D0c c 116 24
mknod pcmC0D0p c 116 16
mknod pcmC0D1c c 116 25
mknod pcmC0D1p c 116 17
mknod timer c 116 33