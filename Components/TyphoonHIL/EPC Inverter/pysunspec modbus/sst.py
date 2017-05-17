import sunspec
import sunspec.core.client as client
d = client.SunSpecClientDevice(client.RTU, 1, 'COM4', max_count=10)
print(d.models)
d.common.read()
print(d.common)
print(d.common.points)
print(d.common.Opt)
print(d.common.Vr)
