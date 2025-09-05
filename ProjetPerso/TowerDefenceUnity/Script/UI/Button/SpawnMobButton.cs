using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SpawnMobButton : MonoBehaviour
{
	[SerializeField] Button button = null;
	[SerializeField] Mob mobRef = null;
	[SerializeField] float cooldownTime = 1;

	bool canSpawn = true;
	ManagerTower managerTower = null;

    void Start()
    {
		button.onClick.AddListener(SpawnMob);
		managerTower = ManagerTower.Instance;
	}

	private void SpawnMob()
	{
		if (!canSpawn)
			return;
		Mob _mob = Instantiate(mobRef, managerTower.PlayerTower.SpawnPointPosition, managerTower.PlayerTower.transform.rotation);
		_mob.SetWithPlayer(true);

		canSpawn = false;
		Invoke("CanSpawn", cooldownTime);
	}

	void CanSpawn()
	{
		canSpawn = true; 
	}
}
