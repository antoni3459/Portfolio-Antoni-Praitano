using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GPE : MonoBehaviour
{
    Action OnUpgrade;

    [SerializeField] bool whitPlayer = false;

	int nbrUpgrade = 0;
    
    public bool WithPlayer => whitPlayer;


	public void SetWithPlayer(bool _whitPlayer)
    {
        whitPlayer = _whitPlayer;
    }

    private void Awake()
    {
        OnUpgrade += Upgrade;
    }

    public void Upgrade()
    {
        nbrUpgrade++;

    }

    void Start()
    {
        
    }

    void Update()
    {
        
    }
}
