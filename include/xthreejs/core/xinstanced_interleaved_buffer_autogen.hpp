#ifndef XTHREE_INSTANCED_INTERLEAVED_BUFFER_HPP
#define XTHREE_INSTANCED_INTERLEAVED_BUFFER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xinterleaved_buffer_autogen.hpp"

namespace xthree
{
    //
    // instanced_interleaved_buffer declaration
    //

    template<class D>
    class xinstanced_interleaved_buffer : public xinterleaved_buffer<D>
    {
    public:

        using base_type = xinterleaved_buffer<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, meshPerAttribute, 1);

    protected:

        xinstanced_interleaved_buffer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using instanced_interleaved_buffer = xw::xmaterialize<xinstanced_interleaved_buffer>;

    using instanced_interleaved_buffer_generator = xw::xgenerator<xinstanced_interleaved_buffer>;

    //
    // instanced_interleaved_buffer implementation
    //

    template <class D>
    inline void xinstanced_interleaved_buffer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(meshPerAttribute, state, buffers);
    }

    template <class D>
    inline void xinstanced_interleaved_buffer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(meshPerAttribute, patch, buffers);
    }

    template <class D>
    inline xinstanced_interleaved_buffer<D>::xinstanced_interleaved_buffer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinstanced_interleaved_buffer<D>::set_defaults()
    {
        this->_model_name() = "InstancedInterleavedBufferModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xinstanced_interleaved_buffer));
//}
#endif