using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerMob : Singleton<ManagerMob>
{
	List<Mob> allPlayerMob = new List<Mob>();
	List<Mob> allBotMob = new List<Mob>();

	public void AddMob(Mob _mob)
	{
		if (_mob.WithPlayer)
			allPlayerMob.Add(_mob);
		else
			allBotMob.Add(_mob);
	}

	public int NbrBotMob()
	{
		return allBotMob.Count;
	}
	public int NbrPlayerMob()
	{
		return allPlayerMob.Count;
	}
}
