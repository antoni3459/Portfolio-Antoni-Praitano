// Fill out your copyright notice in the Description page of Project Settings.


#include "GridNav.h"

AGridNav::AGridNav()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
    PrimaryActorTick.bStartWithTickEnabled = true;
#endif 

}

void AGridNav::BeginPlay()
{
	Super::BeginPlay();
    Generate();
}

void AGridNav::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Debug();
}


bool AGridNav::ShouldTickIfViewportsOnly() const
{
    return true;
}

void AGridNav::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Clear();
    Super::EndPlay(EndPlayReason);
}

void AGridNav::Generate()
{
    Clear();
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            FVector _pos = FVector(x * gap, y * gap, 0) + GetActorLocation();
            UNodeNav* _n = NewObject<UNodeNav>(this, subNode);
            _n->SetPosition(_pos);
            _n->CheckForObstacle();
            data->GetNodes().Add(_n);
        }
    }
    SetSuccessor();
}

void AGridNav::Clear()
{
    data->GetNodes().Empty();
}

void AGridNav::SetSuccessor()
{
    for (int i = 0; i < size * size; i++)
    {
        bool _canRight = i % size != size - 1,
            _canTop = i >= size,
            _canDown = i < (size * size) - size,
            _canLeft = i % size != 0;
        if (_canRight)
            data->GetNodes()[i]->AddSuccessors(i + 1);
        if (_canLeft)
            data->GetNodes()[i]->AddSuccessors(i - 1);
        if (_canTop)
        {
            data->GetNodes()[i]->AddSuccessors(i - size);
            if (_canRight)
                data->GetNodes()[i]->AddSuccessors((i + 1 - size));
            if (_canLeft)
                data->GetNodes()[i]->AddSuccessors((i - 1 - size));
        }
        if (_canDown)
        {
            data->GetNodes()[i]->AddSuccessors(i + size);
            if (_canRight)
                data->GetNodes()[i]->AddSuccessors((i + 1 + size));
            if (_canLeft)
                data->GetNodes()[i]->AddSuccessors((i - 1 + size));
        }
    }
    isGenerate = true;
}

void AGridNav::Debug()
{
   
    if (!isGenerate||!debugMode)
        return;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            DrawDebugBox(GetWorld(), FVector(x * gap, y * gap, 0) + GetActorLocation(), FVector(20), FColor::Blue);
        }
    }

    for (int i = 0; i < data->GetNodes().Num(); i++)
    {
        data->GetNodes()[i]->DrawDebug();
    }
}

