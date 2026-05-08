// Create a new individual with `generations`
person *create_family(int generations)
{
    person *new_person = malloc(sizeof(person));

    if (generations > 1)
    {
        // Recursive step: create parents
        new_person->parent[0] = create_family(generations - 1);
        new_person->parent[1] = create_family(generations - 1);

        // Randomly assign alleles based on parents
        new_person->alleles[0] = new_person->parent[0]->alleles[rand() % 2];
        new_person->alleles[1] = new_person->parent[1]->alleles[rand() % 2];
    }
    else
    {
        // Base case: no parents, assign random alleles
        new_person->parent[0] = NULL;
        new_person->parent[1] = NULL;
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }
    return new_person;
}

// Free memory recursively
void free_family(person *p)
{
    if (p == NULL) return;

    free_family(p->parent[0]);
    free_family(p->parent[1]);
    free(p);
}
