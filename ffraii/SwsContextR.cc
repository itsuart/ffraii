#include "SwsContextR.h"

namespace ffraii {
    const SwsContextR::WrappedType SwsContextR::s_invalidValue = nullptr;

    SwsContextR::SwsContextR()
    : m_resource(s_invalidValue)
    {}

    SwsContextR::SwsContextR(WrappedType resource)
    : m_resource(resource)
    {}

    SwsContextR::~SwsContextR(){
        release();
    }

    void SwsContextR::release(){
        if (m_resource != s_invalidValue){
            sws_freeContext(m_resource);
            m_resource = s_invalidValue;
        }
    }

    SwsContextR::SwsContextR(SwsContextR&& other)
    : m_resource(other.m_resource)
    {
        other.m_resource = s_invalidValue;
    }

    SwsContextR& SwsContextR::operator=(SwsContextR&& other){
        if (&other != this){
            release();
            m_resource = other.m_resource;
            other.m_resource = s_invalidValue;
        }

        return *this;
    }

    // returns true iff wrapped resource is valid
    SwsContextR::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool SwsContextR::ok() const{
        return m_resource != s_invalidValue;
    }

    SwsContextR::operator WrappedType() const{
        return m_resource;
    }

    SwsContextR::WrappedType SwsContextR::unwrap() const {
        return m_resource;
    }

    SwsContextR::WrappedType* SwsContextR::p_value(){
        return &m_resource;
    }

    const SwsContextR::WrappedType* SwsContextR::p_value() const{
        return &m_resource;
    }
}
