using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tower : GPE
{
    [SerializeField] int nbrEmplacementTurret = 1;
    [SerializeField] Transform spawnPoint = null; 

    int NbrEmplacementTurret => nbrEmplacementTurret;

    public Vector3 SpawnPointPosition => spawnPoint.position;

	private void Awake()
	{
	}
	void Start()
    {
		ManagerTower.Instance.AddTower(this);

	}

	void Update()
    {
        
    }
    public void SpawnTurret(Turret _turret)
    {
    }
}
