using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mob : GPE
{
    
    [SerializeField] string nameMob = "";
    [SerializeField] int idMob = 0;
    [SerializeField] int price = 0;
    [SerializeField] StatMob statMob = null;
    [SerializeField] Sprite sprite = null;
    
    public string NameMob => nameMob;
    public int IdMob => idMob;
    public int Price => price;
    public StatMob StatMob => statMob;
    public Sprite Sprite => sprite;
    void Start()
    {
        ManagerMob.Instance.AddMob(this);
    }

    void Update()
    {
        
    }
}
