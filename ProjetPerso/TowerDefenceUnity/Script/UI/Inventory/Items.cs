using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Items : MonoBehaviour
{
    [SerializeField] string nameItem = "";
    [SerializeField] int idItem = 0;
    [SerializeField] int price = 0;
    [SerializeField] int nbrItem = 0;
    [SerializeField] Sprite sprite = null;
    
    
    public string NameItem => nameItem;
    public int IdItem => idItem;
    public int Price => price;
    public int NbrItem => nbrItem;
    public Sprite Sprite => sprite;
    
}
