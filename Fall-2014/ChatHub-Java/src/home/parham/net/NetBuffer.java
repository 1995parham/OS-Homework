package home.parham.net;

import java.util.*;

/**
 * Created by parham on 10/3/14.
 */
public class NetBuffer implements Queue<Message> {

    private ArrayList<Message> messages;

    public NetBuffer(){
        messages = new ArrayList<Message>();
    }


    @Override
    public int size() {
        return messages.size();
    }

    @Override
    public boolean isEmpty() {
        return messages.isEmpty();
    }

    @Override
    public boolean contains(Object o) {
        return messages.contains(o);
    }

    @Override
    public Iterator<Message> iterator() {
        return messages.iterator();
    }

    @Override
    public Object[] toArray() {
        return messages.toArray();
    }

    @Override
    public <T> T[] toArray(T[] ts) {
        return messages.toArray(ts);
    }

    @Override
    public boolean add(Message message) {
        return messages.add(message);
    }

    @Override
    public boolean remove(Object o) {
        return messages.remove(o);
    }

    @Override
    public boolean containsAll(Collection<?> objects) {
        return messages.contains(objects);
    }

    @Override
    public boolean addAll(Collection<? extends Message> messages) {
        return this.messages.addAll(messages);
    }

    @Override
    public boolean removeAll(Collection<?> objects) {
        return messages.removeAll(objects);
    }

    @Override
    public boolean retainAll(Collection<?> objects) {
        return retainAll(objects);
    }

    @Override
    public void clear() {
        messages.clear();
    }

    @Override
    public boolean offer(Message message) {
        return messages.add(message);
    }

    @Override
    public Message remove() {
        return messages.remove(0);
    }

    @Override
    public Message poll() {
        if(messages.size() >= 1){
            return messages.remove(0);
        }else{
            return null;
        }
    }

    @Override
    public Message element() {
         Message message = messages.get(0);
        if(message == null) {
            throw new NoSuchElementException();
        }else{
            return message;
        }

    }

    @Override
    public Message peek() {
        return messages.get(0);
    }
}
