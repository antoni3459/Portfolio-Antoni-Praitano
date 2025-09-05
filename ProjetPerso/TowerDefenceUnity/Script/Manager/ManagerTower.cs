using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerTower : Singleton<ManagerTower>
{
	Tower playerTower = null;
	Tower botTower = null;


	public Tower PlayerTower => playerTower;

	public void AddTower(Tower _tower)
	{
		if (_tower.WithPlayer)
			playerTower = _tower;
		else
			botTower = _tower;
		LifeComponent _lifComponent = _tower.GetComponent<LifeComponent>();
		_lifComponent.onDead += EndParty;
	}

	void EndParty(Transform _winner)
	{

	}
}
