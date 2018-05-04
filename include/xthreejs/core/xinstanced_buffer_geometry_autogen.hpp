#ifndef XTHREE_INSTANCED_BUFFER_GEOMETRY_HPP
#define XTHREE_INSTANCED_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbuffer_geometry_autogen.hpp"

namespace xthree
{
    //
    // instanced_buffer_geometry declaration
    //

    template<class D>
    class xinstanced_buffer_geometry : public xbuffer_geometry<D>
    {
    public:

        using base_type = xbuffer_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<int>, derived_type, maxInstancedCount);


    protected:

        xinstanced_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using instanced_buffer_geometry = xw::xmaterialize<xinstanced_buffer_geometry>;

    using instanced_buffer_geometry_generator = xw::xgenerator<xinstanced_buffer_geometry>;

    //
    // instanced_buffer_geometry implementation
    //


    template <class D>
    inline void xinstanced_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(maxInstancedCount, state, buffers);
    }

    template <class D>
    inline void xinstanced_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(maxInstancedCount, patch, buffers);
    }

    template <class D>
    inline xinstanced_buffer_geometry<D>::xinstanced_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinstanced_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "InstancedBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xinstanced_buffer_geometry));
//}
#endif