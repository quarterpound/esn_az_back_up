ESN Satellite Callhome
=========
This module sends some Satellite usage information periodically.

It POSTs on cron, but not more often than once per 24 hours.

It can be turned off by opting out in settings.

Currently sends:

- base_url (domain + subdirectory)
- satellite version (default: unknown)
- module list of names and versions

Key variables
=========
- 'satellite_callhome_extdata', True/False value of whether the module should send extended data to ESN IT Committee. Basic data must be always send.
- 'satellite_callhome_gateway', the server to which the information will be sent, if not set the default gateway (satellite.esn.org) will be used.
- 'satellite_callhome_lastcall', unix timestamp of last call.
- 'satellite_callhome_update', True/False value of whether the update notification should be shown.
- 'satellite_callhome_message', the message to display including the link.
