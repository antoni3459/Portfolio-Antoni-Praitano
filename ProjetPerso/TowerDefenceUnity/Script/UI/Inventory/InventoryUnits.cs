using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


class InventoryUnits : Inventory
{
    [SerializeField] private Transform buttonContainer; // Conteneur où les boutons seront ajoutés
    [SerializeField] private GameObject buttonPrefab; // Un prefab de bouton
    [SerializeField] private Text mobDetailsText; // Panneau pour afficher les infos

    List<Mob> mobInventory = new List<Mob>();
    
    public List<Mob> MobInventory => mobInventory;

    // Ajoute un Mob à l'inventaire
    public void AddMobToInventory(Mob mob)
    {
        if (mobInventory.Contains(mob))
            return;
        mobInventory.Add(mob);
        CreateButtonForMob(mob);
    }
    public void RemoveMobFromInventory(Mob mob)
    {
        if (mobInventory.Contains(mob))
        {
            mobInventory.Remove(mob);
            Destroy(Button[IndexButton].gameObject); // A Modifier pour supprimer le bon boutton qui correspond au Mob
        }
    }

    // Crée un bouton pour un Mob spécifique
    void CreateButtonForMob(Mob mob)
    {
        GameObject newButton = Instantiate(buttonPrefab, buttonContainer);
        Button.Add(newButton.GetComponent<Button>());
        
        // Configurez l'image et le texte du bouton
        Text buttonText = newButton.GetComponentInChildren<Text>();
        if (buttonText != null)
            buttonText.text = mob.NameMob;

        Image buttonImage = newButton.GetComponentInChildren<Image>();
        if (buttonImage != null && mob.Sprite != null)
            buttonImage.sprite = mob.Sprite;

        Button[IndexButton].onClick.AddListener(() => DisplayMobDetails(mob));
    }

    // Affiche les détails du Mob sélectionné a remplacé par une fenètre quand j'ai le temps
    void DisplayMobDetails(Mob mob)
    {
        if (mobDetailsText == null) return;

        mobDetailsText.text = $"Nom : {mob.NameMob}\n" +
                              $"ID : {mob.IdMob}\n" +
                              $"Prix : {mob.Price}";
    }
}
