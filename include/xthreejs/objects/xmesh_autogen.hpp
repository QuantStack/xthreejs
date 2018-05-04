#ifndef XTHREE_MESH_HPP
#define XTHREE_MESH_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // mesh declaration
    //

    template<class D>
    class xmesh : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, material, xw::xholder<xthree_widget>({}));
        XPROPERTY(xw::xholder<xthree_widget>, derived_type, geometry);
        XPROPERTY(std::string, derived_type, drawMode, "TrianglesDrawMode", xenums::DrawModes);
        XPROPERTY(std::vector<double>, derived_type, morphTargetInfluences, std::vector<double>({}));


    protected:

        xmesh();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh = xw::xmaterialize<xmesh>;

    using mesh_generator = xw::xgenerator<xmesh>;

    //
    // mesh implementation
    //


    template <class D>
    inline void xmesh<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(material, state, buffers);
        xw::set_patch_from_property(geometry, state, buffers);
        xw::set_patch_from_property(drawMode, state, buffers);
        xw::set_patch_from_property(morphTargetInfluences, state, buffers);
    }

    template <class D>
    inline void xmesh<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(material, patch, buffers);
        xw::set_property_from_patch(geometry, patch, buffers);
        xw::set_property_from_patch(drawMode, patch, buffers);
        xw::set_property_from_patch(morphTargetInfluences, patch, buffers);
    }

    template <class D>
    inline xmesh<D>::xmesh()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh<D>::set_defaults()
    {
        this->_model_name() = "MeshModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xmesh));
//}
#endif