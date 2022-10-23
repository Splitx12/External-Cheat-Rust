#pragma once

const unsigned short Crc16Table[256] = {
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

class BaseProjectile
{
public:
	BaseProjectile* activeweapon;
	BaseProjectile* baseprojectile;
	/*Weapons info*/

	uintptr_t GetName()
	{
		DWORD64 Info = safe_read((uintptr_t)this + oItemDefinition, DWORD64);
		DWORD64 DispName = safe_read(Info + odisplayname, DWORD64);
		uintptr_t Str = (safe_read(DispName + 0x18, uintptr_t)); // default
		if (!Str) return 0; return Str;
	}

	int GetItemID()
	{
		UINT64 Info = safe_read((const uintptr_t)this + oItemDefinition, UINT64);
		return safe_read(Info + oItemid, int);
	}

	int UID()
	{
		return safe_read((const uintptr_t)this + 0x28, int);// public uint uid;//public class Item
	}

	/*Functions for weapons*/

	void SAutomatic()
	{
		if (Value::bools::Weapon::IsAutomatic)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write((const uintptr_t)Held + oAuto, 1, bool);
		}
	}


	void SuperBow()
	{
		if (Value::bools::Weapon::SuperBow)
		{
			DWORD64 Held = safe_read((const uintptr_t)this + oHeld, DWORD64);
			safe_write(Held + 0x360, 1, bool);
			safe_write(Held + 0x98, 1.f, float);
		}
	}

	

	
	


	void SuperEoka()
	{
		if (Value::bools::Player::SuperEoka)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + oSuccessFraction, 1.f, float);
			safe_write(Held + 0x388, true);//private bool _didSparkThisFrame;
		}
	}

	void LongHand()
	{
		if (&Value::bools::Player::Longhand)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + 0x298, 4.5f, float);//public float maxDistance; //public class BaseMelee : AttackEntity
		}
	}

	void Spread()
	{
		if (Value::bools::Weapon::NoSpread)
		{
			DWORD64 Held = DriverAPI.Read<DWORD64>((const uintptr_t)this + oHeld);
			DWORD64 recoil = DriverAPI.Read<DWORD64>(Held + oRecoilProperties);
			DriverAPI.Write(recoil + oStancePenalty, 0.f);
			DriverAPI.Write(recoil + oAimconePenalty, 0.f);
			DriverAPI.Write(recoil + oAimCone, 0.f);
			DriverAPI.Write(recoil + oHipAimCone, 0.f);
			DriverAPI.Write(recoil + oAimconePenaltyPerShot, 0.f);

		}
	}

	void Recoil() {
		if (Value::bools::Weapon::NoRecoil)
		{
			DWORD64 Held = DriverAPI.Read<DWORD64>((const uintptr_t)this + oHeld);
			DWORD64 recoil = DriverAPI.Read<DWORD64>(Held + oRecoilProperties);

			DriverAPI.Write(recoil + oRecoilMinYaw, recoilvalYaw);
			DriverAPI.Write(recoil + oRecoilMaxYaw, recoilvalYaw);
			DriverAPI.Write(recoil + oRecoilMinPitch, recoilvalPitch);
			DriverAPI.Write(recoil + oRecoilMaxPitch, recoilvalPitch);
			DWORD64 newrecoil = DriverAPI.Read< DWORD64>(recoil + 0x78);
			DriverAPI.Write(newrecoil + oRecoilMinYaw, recoilvalYaw);
			DriverAPI.Write(newrecoil + oRecoilMaxYaw, recoilvalYaw);
			DriverAPI.Write(newrecoil + oRecoilMinPitch, recoilvalPitch);
			DriverAPI.Write(newrecoil + oRecoilMaxPitch, recoilvalPitch);
		}
	}


	void NoSway()
	{
		if (Value::bools::Weapon::NoRecoil) {
			DriverAPI.Write((const uintptr_t)this + oClothingAccuracyBonus, 1.f);
		}

	}

	void FBullet()
	{
		if (Value::bools::Weapon::FatBullet)
		{
			DWORD64 Held = DriverAPI.Read<DWORD64>((const uintptr_t)this + oHeld);
			UINT64 List = DriverAPI.Read<UINT64>(Held + 0x370);//
			int size = DriverAPI.Read< UINT64>(List + 0x18);
			List = DriverAPI.Read<UINT64>(List + 0x10);
			{
				for (int i = 0; i < size; ++i)
				{
					UINT64 Item = DriverAPI.Read<UINT64>(List + 0x20 + (i * 0x8));
					DriverAPI.Write(Item + 0x2C, fatbulletSize);
				}
			}

		}
	}

	void rapidFire() {

		if (Value::bools::Misc::rapidFire)
		{
			DWORD64 Held = DriverAPI.Read<DWORD64>((const uintptr_t)this + oHeld);
			DriverAPI.Write(Held + 0x650, 0.99f);
			DriverAPI.Write(Held + 0x1f4, 0.f);
		}
	}

	void fastSwitch() {
		if (Value::bools::Misc::fastSwitch)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + 0x1F8, 0, float);//deployDelay | instant deploy > AttackEntity
		}
	}

	void instantCompound() {
		if (Value::bools::Misc::instantCompound)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + 0x390, 0);//stringHoldDurationMax
			safe_write(Held + 0x394, 1000000);//stringBonusDamage
			safe_write(Held + 0x3A0, 1000000);//movementPenaltyRampUpTime
		}
	}

	unsigned short CRC(unsigned char* pcBlock, unsigned short len)
	{
		unsigned short crc = 0xFFFF;
		while (len--)
			crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ *pcBlock++];
		return crc;
	}

	wchar_t GShortName(int* len)
	{
		DWORD64 Info = safe_read((const uintptr_t)this + oItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)safe_read(Info + oShortname, DWORD64));
		int leng = safe_read((const uintptr_t)Str + 0x10, int);
		if (!leng) return NULL;
		if (len)*len = leng;
		return Str->str;
	}


	USHORT GetNameHash()
	{
		int Len;
		UCHAR* ShortName = (UCHAR*)GShortName(&Len);
		if (ShortName == nullptr) return 0;
		return CRC(ShortName, (Len * 2));
	}

private:
};
