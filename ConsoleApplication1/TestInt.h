#ifndef TESTINT_H
#define TESTINT_H


#include "acutest.h"

#include "ArraySequence.h""
#include "ListSequence.h"
#include "NodeSequence.h"

void Test_IntArraySequence(void)
{
    ArraySequence<int>* sequence = new ArraySequence<int>();

    TEST_CHECK(sequence->getLength() == 0);

    sequence->append(23);

    TEST_CHECK(sequence->getLength() == 1);
    TEST_CHECK(sequence->getFirst() == 23);
    TEST_CHECK(sequence->getLast() == 23);
    TEST_CHECK(sequence->get(0) == 23);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(1), std::exception);

    sequence->append(43);

    TEST_CHECK(sequence->getLength() == 2);
    TEST_CHECK(sequence->getFirst() == 23);
    TEST_CHECK(sequence->getLast() == 43);
    TEST_CHECK(sequence->get(0) == 23);
    TEST_CHECK(sequence->get(1) == 43);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(2), std::exception);

    sequence->prepend(53);

    TEST_CHECK(sequence->getFirst() == 53);
    TEST_CHECK(sequence->getLast() == 43);
    TEST_CHECK(sequence->get(0) == 53);
    TEST_CHECK(sequence->get(1) == 23);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(3), std::exception);

    ArraySequence<int>* subsequence = dynamic_cast<ArraySequence<int>*>(sequence->getSubsequence(1, 1));

    TEST_CHECK(subsequence->getLength() == 1);
    TEST_CHECK(subsequence->getFirst() == 23);
    TEST_CHECK(subsequence->getLast() == 23);

    subsequence->remove(23);

    TEST_CHECK(subsequence->getIsEmpty());

    delete subsequence;
    delete sequence;
}

void Test_IntListSequence(void)
{
    ListSequence<int>* sequence = new ListSequence<int>();

    TEST_CHECK(sequence->getLength() == 0);

    sequence->append(23);

    TEST_CHECK(sequence->getLength() == 1);
    TEST_CHECK(sequence->getFirst() == 23);
    TEST_CHECK(sequence->getLast() == 23);
    TEST_CHECK(sequence->get(0) == 23);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(1), std::exception);

    sequence->append(43);

    TEST_CHECK(sequence->getLength() == 2);
    TEST_CHECK(sequence->getFirst() == 23);
    TEST_CHECK(sequence->getLast() == 43);
    TEST_CHECK(sequence->get(0) == 23);
    TEST_CHECK(sequence->get(1) == 43);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(2), std::exception);

    sequence->prepend(53);

    TEST_CHECK(sequence->getFirst() == 53);
    TEST_CHECK(sequence->getLast() == 43);
    TEST_CHECK(sequence->get(0) == 53);
    TEST_CHECK(sequence->get(1) == 23);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(3), std::exception);

    ListSequence<int>* subsequence = dynamic_cast<ListSequence<int>*>(sequence->getSubsequence(1, 1));

    TEST_CHECK(subsequence->getLength() == 1);
    TEST_CHECK(subsequence->getFirst() == 23);
    TEST_CHECK(subsequence->getLast() == 23);

    subsequence->remove(23);

    TEST_CHECK(subsequence->getIsEmpty());

    delete subsequence;
    delete sequence;
}

void Test_IntNodeSequence(void)
{
	NodeSequence<int>* sequence = new NodeSequence<int>();
	sequence->addelem(7);
	sequence->addelem(8);
	sequence->addelem(9);
	sequence->addelem(10);
	sequence->addelem(11);
	sequence->swapto();
	sequence->deletelem(0);
	sequence->deletelem( sequence->getLength() - 1 );
	sequence->deletelem(1);
	return;

}


#endif // TESTINT_H
