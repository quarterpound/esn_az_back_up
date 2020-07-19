; This is the makefile for satellite_base
; The modules here are hard dependencies for the satellite.
; Modules that are also a dependency of esn_base are in its makefile,
; Modules that could be turned off are in satellite.make

api = 2
core = 7.x

; Modules

projects[realname][subdir] = contrib
projects[realname][version] = 1.4

